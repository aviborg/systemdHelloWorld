all:
	sudo g++ -o /usr/bin/sHW -lsystemd systemdHelloWorld.cpp
	sudo cp sHW.service /usr/lib/systemd/system/.

clean:
	sudo systemctl stop sHW
	sudo rm -f /usr/lib/systemd/system/sHW.service
	sudo rm -f /usr/bin/sHW