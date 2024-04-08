# Development Environment

- For development environment a docker container is created. The container files are stored in "ngvoice_env/cppenv" folder.

- For debugging VsCode is used. The vscode is connected to container via SSH. Vscode debug configurations are stored in ".vscode"(ignore from git) folder.

- The hostname

## Test Environment

## Unit tests

-- Have not been done for this case study because of urgency and time limit but normally it has to be done for every function before functions are created.

## Integration test

- For sip messaging test an asterisk container is created with the hostname: "mockasterisk". Basically in this case study asterisk gives interface to register the sip user, answers the call and waits for the call for 60 seconds to give time to terminate the call.

- For following sip messages, tcpdump is used:

  `tcpdump -A -s 0 -n -nn -i any port 5060`