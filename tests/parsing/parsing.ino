enum class PacketType {
    ERRO,
    INIT,
    RACC,
    DACC,
    RTMP,
    DTMP,
    RHES,
    DHES,
    RPOT,
    DPOT,
};

typedef struct {
  PacketType type;
  String content;
} Packet;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial) {}
  Serial.println("ready");
}

String packet = "(INIT,2543,4321,4432)";
void loop() {
  // put your main code here, to run repeatedly:
  Packet bruh = generatePacket(packet);
  switch(bruh.type){
    case PacketType::DTMP:
      Serial.println("hee hoo");
  }
  //Serial.println("content: " + bruh.content);
}

Packet generatePacket(String raw){
  Packet p;
  p.content = "";
  if(raw[0] != '('){
    p.type = PacketType::ERRO;
    return p;
  }
  
  // get type
  String type = "";
  for(int i = 1; i < 5; i++){
    type += raw[i];
  }
  if(type.equals("INIT")){
    p.type = PacketType::INIT;
  } else if(type.equals("RACC")){
    p.type = PacketType::RACC;
  } else if(type.equals("DACC")){
    p.type = PacketType::DACC;
  } else if(type.equals("RTMP")){
    p.type = PacketType::RTMP;
  } else if(type.equals("DTMP")){
    p.type = PacketType::DTMP;
  } else if(type.equals("RHES")){
    p.type = PacketType::RHES;
  } else if(type.equals("DHES")){
    p.type = PacketType::DHES;
  } else if(type.equals("RPOT")){
    p.type = PacketType::RPOT;
  } else if(type.equals("DPOT")){
    p.type = PacketType::DPOT;
  } else {
    p.type = PacketType::ERRO;
  }

  // fill content
  for(int i = 6; i < raw.length()-1; i++){
    p.content += raw[i];
  }
  return p;
}
