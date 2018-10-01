# systemdHelloWorld

A simple tutorial on how to create a linux systemd Hello World service. It has watchdog functionality. This was created for a Raspberry Pi but it should work on most Linux distributions.

To compile you need the systemd libraries, get them by:
```sudo apt-get install libsystemd-dev```

Then make it by running 
```make all```

Start the service
```sudo systemctl start sHW```

Check the status
```sudo systemctl status sHW```

Check all logmessages
```grep -in helloworld /var/log/syslog```

Stop the service
```sudo systemctl stop sHW```

Clean the files
```make clean```

Try the watchdog by uncommenting the code which increase the delay.




