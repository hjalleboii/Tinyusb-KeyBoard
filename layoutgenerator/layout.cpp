#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>
#include <unordered_map>
#include "rapidxml/rapidxml.hpp"
#include <sstream>
#include <algorithm>
#include <unordered_set>
#define BIT(x) 1 << x

unsigned short character_to_int(const std::string& str);
unsigned char parsemodifierbits(const std::string& str);
unsigned char getTINYUSBMODBITS(unsigned char internalmodbits);
std::vector<std::string> splitString(const std::string& input);

enum class MODIFIERBITS{
    SHIFT = BIT(0),
    ALTGR = BIT(1),
    CTRL  = BIT(2),
    ALT   = BIT(3),
    INVALID  = BIT(4)
};

int main(int argc, char* argv[]) {
    
    if (argc < 4){
        std::cout << "Not enoguh prameters!\n"
        << "\tParameters are:\n"
        << "\t\t1) XML-LAYOUTFILE\n"
        << "\t\t2) LAYOUTNAME\n"
        << "\t\t3) output folder!\n";
    }
    std::string xmlfile = argv[1];
    std::string layoutname_l = argv[2];
    std::string layoutname = layoutname_l;
    std::transform(layoutname.begin(),layoutname.end(),layoutname.begin(),::toupper);
    std::string outfile_h = argv[3];
    outfile_h += "/"+layoutname_l+".h";
    std::string outfile_src = argv[3];
    outfile_src += "/"+layoutname_l+".c";
    //std::vector<std::pair<uint, std::string>> scancodes;
    std::unordered_map<std::string,uint> scancodes;
    struct ResultMethod {
        uint scancode;
        u_char mods;
    };

    std::unordered_map<uint, std::vector<ResultMethod>> map;

    struct conversion_case{
        uint c;
        uint scancode;
        u_char modbits;
        //std::string keyName;
    };
    std::vector<conversion_case> cases;
    std::vector<conversion_case> cases_suitableforswitch;

    rapidxml::xml_document<> doc;
    rapidxml::xml_node<> *root_node;

    std::ifstream file(xmlfile);
    std::string content{(std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>()};
    file.close();
    // Replace """ with "'"
    size_t pos = 0;
    while ((pos = content.find("\"\"\"", pos)) != std::string::npos) {
        content.replace(pos, 3, "\'\"\'");
        pos += 3;
    }

    // Replace "&" with "&amp;"
    pos = 0;
    while ((pos = content.find("\"&\"", pos)) != std::string::npos) {
        content.replace(pos, 3, "\"&amp;\"");
        pos += 6;
    }

    // Replace "<" with "&lt;"
    pos = 0;
    while ((pos = content.find("\"<\"", pos)) != std::string::npos) {
        content.replace(pos, 3, "\"&lt;\"");
        pos += 5;
    }

    doc.parse<0>(&content[0]);

    root_node = doc.first_node();
    if(!root_node)return -1;

    auto* PhysicalKeys_node = root_node->first_node("PhysicalKeys");
    if(!PhysicalKeys_node)return -1;
    

    for (rapidxml::xml_node<> *scancode_node = PhysicalKeys_node->first_node("PK"); scancode_node; scancode_node = scancode_node->next_sibling()) {

        rapidxml::xml_attribute<>*attribute = scancode_node->first_attribute("SC");
        u_short sc = 0;
        if(attribute){
            
            sc = std::stol(attribute->value(), 0, 16);
            
            rapidxml::xml_attribute<>* attribute_vk = scancode_node->first_attribute("VK");
            if(attribute_vk){
                std::string name = attribute_vk->value();
                if( scancodes.find(name) == scancodes.end()){
                    scancodes [name] = sc;
                }else{
                    scancodes [name] = std::min(scancodes[name],(unsigned int)sc);
                }
            }
            
        }
        for (rapidxml::xml_node<> *result_node = scancode_node->first_node("Result"); result_node; result_node = result_node->next_sibling()) {
            rapidxml::xml_attribute<>* text_attribute=result_node->first_attribute("Text");
            if(text_attribute) {
                std::string character= text_attribute->value();
                if(character.size() >2)continue; // onlye accept characters of size 2
                uint charint = character_to_int(character);
                u_char modbits_e = 0;
                if(rapidxml::xml_attribute<>* with_attribute=result_node->first_attribute("With")){
                    modbits_e = parsemodifierbits(with_attribute->value());
                }
                if(!(modbits_e&(u_char)MODIFIERBITS::INVALID))
                map[charint].push_back({sc,modbits_e});
            }
        }

    }
    for(auto it =map.begin();it!=map.end();++it){
        if(it->second.size() == 0)continue;
        size_t simplestsolution = 0;
        u_char modbits = -1;
        for(size_t i = 0; i < it->second.size();i++){
            if( it->second[i].mods < modbits){
                modbits = it->second[i].mods;
                simplestsolution =i;
            }
        }
        cases.push_back({
            it->first,
            it->second[simplestsolution].scancode,
            getTINYUSBMODBITS( it->second[simplestsolution].mods)});
        
    }

    std::vector<std::string> NONECHARKEYENUMS{
    "LSHIFT",
    "RSHIFT",
    "LMENU",
    "RMENU",
    "LCONTROL",
    "RCONTROL",
    "LWIN",
    "RWIN",
    "UP",
    "DOWN",
    "LEFT",
    "RIGHT",
    "RETURN",
    "TAB",
    "BACK",
    "F1",
    "F2",
    "F3",
    "F4",
    "F5",
    "F6",
    "F7",
    "F8",
    "F9",
    "F10",
    "F11",
    "F12",
    "F13",
    "F14",
    "F15",
    "F16",
    "F17",
    "F18",
    "F19",
    "F20",
    "F21",
    "F22",
    "F23",
    "F24",
    "ESCAPE"

    };

    std::ofstream out_src(outfile_src);
    std::ofstream out_h(outfile_h);
    out_h << "#ifndef " << layoutname 
    << "\n#define " << layoutname << "\n\n"
    << "#include \"layout_utils.h\"\n";

    out_src << "#include \""<<  layoutname_l <<".h" << "\"\n\n"
    << "#ifdef __cplusplus\n"
    << "extern \"C\"{\n"
    << "#endif\n\n";
    

    int padding = 30;
    for (const auto& scancode : scancodes) {
        std::string full_keyname = layoutname + "_" + scancode.first;
        out_src << "#define " << full_keyname;
        if(padding > full_keyname.size()){
            for(int i = 0; i < padding-full_keyname.size();i++){
                out_src << ' ';
            }
        }
        out_src << " 0x" << std::hex << scancode.second << "\n";

    }
/*
    out << "#ifndef SCANCODE_MODBITS\n"
    << "#define SCANCODE_MODBITS\n"
    << "struct scancode_modbits {unsigned short scancode; unsigned char modbits;};\n"
    << "#endif\n"
    
    << "#ifndef KEYBOARD_NONCHAR_KEYS_ENUM\n"
    << "#define KEYBOARD_NONCHAR_KEYS_ENUM\n"
    << "enum KEYBOARD_NONCHAR_KEYS{\n";
    for(unsigned int i = 0; i <NONECHARKEYENUMS.size(); i++){

        out << "    KEY_" << NONECHARKEYENUMS[i]<< " = " << std::dec << i+1 << ",\n";
    }

    out << "};\n";
    out << "#endif\n";*/

    conversion_case caseslookup[128]={};

    for(const auto& cas:cases){
        if (cas.c < 128){
            caseslookup[cas.c] = cas;
        }else{
            cases_suitableforswitch.push_back(cas);
        }
    }

    out_h << "unsigned short "<<layoutname <<"_layout_key_to_scancode(unsigned int key);\n";
    out_src <<  "unsigned short "<<layoutname <<"_layout_key_to_scancode(unsigned int key){\n";
    out_src << "    switch(key)\n";
    out_src << "        {\n";
    for(const auto& ENUM: NONECHARKEYENUMS){
        if(scancodes.find("VK_"+ENUM) !=scancodes.end())
        out_src << "    case KEY_" << ENUM << ": return "<<layoutname <<"_VK_" << ENUM <<";\n";

    }
    out_src << "        }\n";
    out_src << "    return 0;\n";
    out_src << "};\n";

    out_h << "struct scancode_modbits " << layoutname<<"_char_to_scancode_modbits(unsigned short c);\n";
    out_src << "struct scancode_modbits " << layoutname<<"_char_to_scancode_modbits(unsigned short c){\n";
    out_src << "    if(c < 128){\n";
    out_src << "        const struct scancode_modbits char_lookup[128]={\n";
    for(const auto& look: caseslookup){
        if(look.c !=0){
            out_src << "            {0x"<< std::hex << look.scancode;
            out_src << ", 0x"<<std::hex<< (unsigned int)look.modbits<< "},\n";
        }else{
            out_src << "            {0x00, 0x00},\n";
        }

    }
    out_src << "        };\n";
    out_src << "    return char_lookup[c];\n";
    out_src << "    }\n";
    out_src << "    switch(c)\n";
    out_src << "        {\n";
    for(const auto& switchcase: cases_suitableforswitch){
        out_src << "            case 0x"<< std::hex<<switchcase.c << ": return (struct scancode_modbits){0x"<< switchcase.scancode << ",";
        out_src << "0x" << std::hex << (unsigned int)switchcase.modbits << "};\n";

    }
    out_src << "        }\n"
    << "    return (struct scancode_modbits){0,0};\n"
    << "}\n"
    << "#ifdef __cplusplus\n"
    << "}\n"
    << "#endif\n";
    out_h<< "#endif\n";

    out_src.close();
    out_h.close();



    return 0;
}


enum KEYBOARD_NONCHAR_KEYS{
    
};

unsigned short character_to_int(const std::string& str){
    unsigned short v=0;
    
    if(str.size() > sizeof(v))return -1;
    memcpy(&v,str.data(),str.size());
    return v;
}


std::vector<std::string> splitString(const std::string& input) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string token;

    while (ss >> token) {
        result.push_back(token);
    }

    return result;
}

unsigned char parsemodifierbits(const std::string& str){
    auto keywords = splitString(str);
    unsigned char modbits =0;
    if(str.find("VK_CAPITAL") != str.npos){
        modbits |= (unsigned char)MODIFIERBITS::INVALID;
    }else 
    if(str.find("VK_NUMLOCK") != str.npos){
        modbits |= (unsigned char)MODIFIERBITS::INVALID;
    }else 
    if(str.find("VK_SHIFT") != str.npos){
        modbits |= (unsigned char)MODIFIERBITS::SHIFT;
    }else
    if(str.find("VK_CONTROL VK_MENU") != str.npos){
        modbits |= (unsigned char)MODIFIERBITS::ALTGR;
    }else
    if(str.find("VK_CONTROL") != str.npos){
        modbits |= (unsigned char)MODIFIERBITS::CTRL;
    }else
    if(str.find("VK_ALT") != str.npos){
        modbits |= (unsigned char)MODIFIERBITS::ALT;
    }
    return modbits;
}
/*
typedef enum
{
  KEYBOARD_MODIFIER_LEFTCTRL   = TU_BIT(0), ///< Left Control
  KEYBOARD_MODIFIER_LEFTSHIFT  = TU_BIT(1), ///< Left Shift
  KEYBOARD_MODIFIER_LEFTALT    = TU_BIT(2), ///< Left Alt
  KEYBOARD_MODIFIER_LEFTGUI    = TU_BIT(3), ///< Left Window
  KEYBOARD_MODIFIER_RIGHTCTRL  = TU_BIT(4), ///< Right Control
  KEYBOARD_MODIFIER_RIGHTSHIFT = TU_BIT(5), ///< Right Shift
  KEYBOARD_MODIFIER_RIGHTALT   = TU_BIT(6), ///< Right Alt
  KEYBOARD_MODIFIER_RIGHTGUI   = TU_BIT(7)  ///< Right Window
}hid_keyboard_modifier_bm_t;*/

unsigned char getTINYUSBMODBITS(unsigned char internalmodbits){
    unsigned char modbits = 0;
    if(internalmodbits & (u_char)MODIFIERBITS::SHIFT)
        modbits |= BIT(1);
    if(internalmodbits & (u_char)MODIFIERBITS::ALTGR)
        modbits |= BIT(6);
    if(internalmodbits & (u_char)MODIFIERBITS::ALT)
        modbits |= BIT(2);
    if(internalmodbits & (u_char)MODIFIERBITS::CTRL)
        modbits |= BIT(0);
    return modbits;
}