#include <unistd.h>  // needed for sleep
#include <signal.h>
#include <syslog.h>
#include <stdio.h>   //needed for sprintf
#include <systemd/sd-daemon.h> // needed for sd_notify, if compiler error try to run >> sudo apt-get install libsystemd-dev


volatile sig_atomic_t stopprogram;


/**
 * \brief Callback function for handling signals.
 * \param	sig	identifier of signal
 */
void handle_signal(int sig)
{
	if (sig) {
		char s[64]; 
		sprintf(s,"systemdHelloWorld received: %ld\n", sig);
		syslog(LOG_INFO, s);
		stopprogram = 1;
	} 
}

int main(void)
{
	int n ;
	for (n = 1; n < 32; n++) {
		signal(n, handle_signal);
	}
	syslog(LOG_INFO, "systemdHelloWorld started\n");
	n = 15;
    while(!stopprogram) {
        /* TODO: do something useful here ;-) */
		syslog(LOG_INFO, "systemdHelloWorld is ALIVE!\n");
		sd_notify(0,"WATCHDOG=1");
        sleep(n);
		//n+=5;  Uncomment this to test the watchdog
    }
	
	syslog(LOG_INFO, "systemdHelloWorld stopped\n");
	return 0;
}