#ifndef ENTITIES_H
#define ENTITIES_H

struct Cruds
{
    std::string user{};
    std::string room{};
};

struct Message
{
  std::string type{};              
  std::string username{};          
  std::string user_id{};           
  std::string content{};           
  std::string timestamp{};         
  std::string channel{};     
  
  std::string to_string() const {
        std::ostringstream oss;
        oss << "Message: "
            << "\n\ttype: " << type
            << "\n\tusername: " << username
            << "\n\tuser_id: " << user_id
            << "\n\tcontent: " << content
            << "\n\ttimestamp: " << timestamp
            << "\n\tchannel: " << channel
            << "\n";
        return oss.str();
    
    };
};

#endif