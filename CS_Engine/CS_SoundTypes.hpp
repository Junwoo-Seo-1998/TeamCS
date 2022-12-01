#pragma once 
#include <string> 
 
 
enum class CS_SoundTypes {  
Activate, 
Back, 
BGM, 
Deactivate, 
Explosion1, 
Explosion2, 
Gatling, 
Pistol, 
Select, 
Shotgun, 
INVALID_Sound 
}; 
 
 
inline CS_SoundTypes StringToSound(const std::string& string) { 
if(string == "Activate") return CS_SoundTypes::Activate; 
if(string == "Back") return CS_SoundTypes::Back; 
if(string == "BGM") return CS_SoundTypes::BGM; 
if(string == "Deactivate") return CS_SoundTypes::Deactivate; 
if(string == "Explosion1") return CS_SoundTypes::Explosion1; 
if(string == "Explosion2") return CS_SoundTypes::Explosion2; 
if(string == "Gatling") return CS_SoundTypes::Gatling; 
if(string == "Pistol") return CS_SoundTypes::Pistol; 
if(string == "Select") return CS_SoundTypes::Select; 
if(string == "Shotgun") return CS_SoundTypes::Shotgun; 
return CS_SoundTypes::INVALID_Sound; 
} 
inline std::string SoundToString(const CS_SoundTypes type) { 
if(type == CS_SoundTypes::Activate) return "Activate"; 
if(type == CS_SoundTypes::Back) return "Back"; 
if(type == CS_SoundTypes::BGM) return "BGM"; 
if(type == CS_SoundTypes::Deactivate) return "Deactivate"; 
if(type == CS_SoundTypes::Explosion1) return "Explosion1"; 
if(type == CS_SoundTypes::Explosion2) return "Explosion2"; 
if(type == CS_SoundTypes::Gatling) return "Gatling"; 
if(type == CS_SoundTypes::Pistol) return "Pistol"; 
if(type == CS_SoundTypes::Select) return "Select"; 
if(type == CS_SoundTypes::Shotgun) return "Shotgun"; 
return "INVALID_Sound"; 
} 
