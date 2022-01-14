void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial) {}
  Serial.write("ready\n");
}

enum class PacketType {
    INIT,
    RACC,
    DACC,
    RTMP,
    DTMP,
    RHES,
    DHES,
    RPOT,
    DPOT,
    ERRO
};

typedef struct {
  PacketType type;
  String content;
} Packet;

int incomingByte = 0;
int readingPacket = 0;
String hehe;
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    incomingByte = Serial.read();
    Serial.print("I received: ");
    
    Serial.println(incomingByte, DEC);
    if(incomingByte == '('){
      Serial.println("begin packet");
      readingPacket = 1;
      hehe = "";
    }

    if(readingPacket){
      hehe += (char) incomingByte;
      if(incomingByte == ')'){
        readingPacket = 0;
        Serial.println("Packet: " + hehe);
      }
      
    } // end if Reading packet
  }
}

String getPacket(){
  String p = "";
 
  return p;
}
