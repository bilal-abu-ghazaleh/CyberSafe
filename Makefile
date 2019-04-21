#------------------------------------------------------------------------------
# Macro definitions
CXXFLAGS = -O1 -g -Wall -std=c++17
OBJ = CyberSafe.o cam.o tools.o connections.o encryptionAndFirewall.o softwareAndDNS.o passwords.o
TARGET = CyberSafe
#------------------------------------------------------------------------------
# Rules
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) -o $@ $(OBJ)
clean:
	rm -f $(OBJ) $(TARGET)
#------------------------------------------------------------------------------
# Dependencies
CyberSafe.o: CyberSafe.cpp cam.hpp tools.hpp
cam.o: cam.cpp cam.hpp tools.hpp
connections.o: connections.cpp connections.hpp tools.hpp
encryptionAndFirewall.o: encryptionAndFirewall.cpp encryptionAndFirewall.hpp tools.hpp
softwareAndDNS.o: softwareAndDNS.cpp softwareAndDNS.hpp tools.hpp
passwords.o: passwords.cpp passwords.hpp tools.hpp
tools.o: tools.cpp tools.hpp
