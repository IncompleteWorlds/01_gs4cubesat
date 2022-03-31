


Libraries and Settings
-----------------------------------------------
Compiler
Compiler options:
-std=c++11
-m64
-Wall
-Weffc++

Other compiler options (all configurations):

-fexceptions

Linker.
Link libraries:


avrocpp
zeromq
Common
Security_Access_Control

pthread


Install in /usr/local/include or /usr/include:
avro-cpp-1.8.2
zmq
cppzmq
log4cpp
sqlite3
SqlBrowser
bitstream (bitstream-master)
SRombauts-SqliteCpp
boost 1.60 or greater

jzmq (Java Zmq)





Search Diretories:
Compiler:

include
../Common/include
../Security_Access_Control/include

Linker:
/usr/local/lib

../Common/bin/Debug | Release
../Security_Access_Control/bin/Debug | Release

Convert String
--------------------------------------------------------------
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>


const char* starting = "001122AABBCC";
int main()
{
    std::string starting_str = starting;
    std::vector<unsigned char> ending;
    ending.reserve( starting_str.size());
    for (int i = 0 ; i < starting_str.length() ; i+=2) {
        std::string pair = starting_str.substr( i, 2 );
        ending.push_back(::strtol( pair.c_str(), 0, 16 ));
    }

    for(int i=0; i<ending.size(); ++i) {
        printf("0x%X\n", ending[i]);
    }

}

string textMessageId = to_string(messageIdCounter);

std::itos()


AVRO
----------------------------------------------------------------
Protocols not supported in C++ avrogencpp


JSON C++
----------------------------------------------------------------
Linux has libjson library installed. I could reuse it instead of
json11.hpp


Code Snipp
----------------------------------------------------------------

std::string generate_address() {
  std::ostringstream addr;
  addr << "server" << address_counter++;
  return addr.str();
}


http://avro.apache.org/docs/current/gettingstartedjava.html



AX.25 Frame
----------------------------------------------------------------

byte
SendData[27]
 =
{0x86, OxA2, 0x40, 0x40, 0x40, 0x40, 0x60,OxAE, 0x64,Ox8C,OxA6,0x40,  0x40,Ox68,OxA4,0x8A,
  0x98,  0x82,OxB2,  0x40,  0x61,Ox3F,OxFO, 0x54,  0x65,0x73,0x74)



AVRO messages.   Compile C++  Java
------------------------------------------------

$ avrogencpp -i cpx.json -o cpx.hh -n c

Where:
-n = namespace
it seems the namespace in the JSON is not taken into account



$ java -jar /path/to/avro-tools-1.8.1.jar compile schema <schema file> <destination>



AVRO messages.   Encode and Decode    C++  Java
---------------------------------------------------------------

// avro::fileOutputStream() instead of avro::memoryOutputStream()
// avro::fileInputStream() instead of avro::memoryInputStream()

AVRO_DECL std::auto_ptr<InputStream> avro::memoryInputStream(const uint8_t *data, size_t len);

std::auto_ptr<avro::OutputStream> out = avro::memoryOutputStream();


avro::EncoderPtr e = avro::binaryEncoder();  // Create a binary encoder
//  avro::jsonEncoder() create a JSON encoder

e->init(*out);
c::cpx c1;
c1.re = 1.0;
c1.im = 2.13;
avro::encode(*e, c1);


Decode an AVRO Message

std::auto_ptr<avro::InputStream> in = avro::memoryInputStream(*out);
avro::DecoderPtr d = avro::binaryDecoder();   // Create a binary decoder
// avro::jsonDecoder()  Create a JSON decoder

d->init(*in);

c::cpx c2;
avro::decode(*d, c2);
std::cout << '(' << c2.re << ", " << c2.im << ')' << std::endl;



User user1 = new User();
user1.setName("Alyssa");
user1.setFavoriteNumber(256);
// Leave favorite color null

// Alternate constructor
User user2 = new User("Ben", 7, "red");

// Construct via builder
User user3 = User.newBuilder()
             .setName("Charlie")
             .setFavoriteColor("blue")
             .setFavoriteNumber(null)
             .build();



// Serialize user1, user2 and user3 to disk
DatumWriter<User> userDatumWriter = new SpecificDatumWriter<User>(User.class);
DataFileWriter<User> dataFileWriter = new DataFileWriter<User>(userDatumWriter);

dataFileWriter.create(user1.getSchema(), new File("users.avro"));


dataFileWriter.append(user1);
dataFileWriter.append(user2);
dataFileWriter.append(user3);
dataFileWriter.close();


// Deserialize Users from disk
DatumReader<User> userDatumReader = new SpecificDatumReader<User>(User.class);
DataFileReader<User> dataFileReader = new DataFileReader<User>(file, userDatumReader);
User user = null;
while (dataFileReader.hasNext()) {
    // Reuse user object by passing it to next(). This saves us from
    // allocating and garbage collecting many objects for files with
    // many items.
    user = dataFileReader.next(user);
    System.out.println(user);
}


AVRO. Compile schema. Read & Write from / to file
-------------------------------------------------------------------------


00001 
00019 #include <fstream>
00020 
00021 #include "cpx.hh"
00022 #include "avro/Encoder.hh"
00023 #include "avro/Decoder.hh"
00024 #include "avro/ValidSchema.hh"
00025 #include "avro/Compiler.hh"
00026 #include "avro/DataFile.hh"
00027 
00028 
00029 avro::ValidSchema loadSchema(const char* filename)
00030 {
00031     std::ifstream ifs(filename);
00032     avro::ValidSchema result;
00033     avro::compileJsonSchema(ifs, result);
00034     return result;
00035 }
00036 
00037 int
00038 main()
00039 {
00040     avro::ValidSchema cpxSchema = loadSchema("cpx.json");
00041 
00042     {
00043         avro::DataFileWriter<c::cpx> dfw("test.bin", cpxSchema);
00044         c::cpx c1;
00045         for (int i = 0; i < 100; i++) {
00046             c1.re = i * 100;
00047             c1.im = i + 100;
00048             dfw.write(c1);
00049         }
00050         dfw.close();
00051     }
00052 
00053     {
00054         avro::DataFileReader<c::cpx> dfr("test.bin", cpxSchema);
00055         c::cpx c2;
00056         while (dfr.read(c2)) {
00057             std::cout << '(' << c2.re << ", " << c2.im << ')' << std::endl;
00058         }
00059     }
00060     return 0;
00061 }






=========================================================


Thread
-------------------------------------------------------

#include <thread>

    void run() {
        std::vector<std::thread> threads(std::thread::hardware_concurrency()-1);
        for (auto& t : threads)
            t = std::thread(&proton::container::run, container_.get());
        container_->run();      // Use this thread too.
        for (auto& t : threads)
            t.join();
    }


void stopFunction()
{
    this_thread::sleep_for( chrono::seconds(7) );

    TransportQpidIF::getInstance().stop();
}

thread  t ( stopFunction );

t.detach();


void runTest()
{
    this_thread::sleep_for( chrono::seconds(2) );

    IW::List_Passes    avroMsg;
    IW::MsgReturnData  returnData;

    ExternalIF::getInstance().getPasses("mi01", "sa01", "gs01", "2016-01-01", "2016-02-01", avroMsg, returnData);

    // Send Init message to M&C
    FdsModuleManager::sendInitMessage();
}


Condition Variables
------------------------------------------------------
#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
    // Wait until main() sends data
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, []{return ready;});

    // after the wait, we own the lock.
    std::cout << "Worker thread is processing data\n";
    data += " after processing";

    // Send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed\n";

    // Manual unlocking is done before notifying, to avoid waking up
    // the waiting thread only to block again (see notify_one for details)
    lk.unlock();
    cv.notify_one();
}

int main()
{
    std::thread worker(worker_thread);

    data = "Example data";
    // send data to the worker thread
    {
        std::lock_guard<std::mutex> lk(m);
        ready = true;
        std::cout << "main() signals data ready for processing\n";
    }
    cv.notify_one();

    // wait for the worker
    {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, []{return processed;});
    }
    std::cout << "Back in main(), data = " << data << '\n';

    worker.join();
}


Observer pattern
----------------------------------------------------
#include <string>
#include <set>
using namespace std;
class Subject;
class Observer {
public:
  virtual void update(Subject & subject) = 0;
};
// also knows as Observable in literature
class Subject
{
  string state;
  set<Observer*> observers;
public:
  void attachObserver(Observer *o) { observers.insert(o); }
  void detachObserver(Observer *o) { observers.erase(o); }
  void notifyObservers()
  {
    for (auto &o : observers)
    {
      o->update(*this);
    }
  }
  string getState() { return state; }
  void changeState(const string & s)
  {
    state = s;
    notifyObservers();
  }
};
class ObserverImpl : public Observer
{
  string state;
public:
  void update(Subject & sbj) override
  {
    state = sbj.getState();
  }
  string getState() { return state; }
};
int main()
{
  ObserverImpl a, b, c;
  Subject subject;
  subject.attachObserver(&a);
  subject.attachObserver(&b);
  subject.attachObserver(&c);
  subject.changeState("Observer pattern");
  cout << a.getState() << endl;
  cout << b.getState() << endl;
  cout << c.getState() << endl;
  return 0;
}


avro files
-------------------------------------------------------
#include <fstream>
00020
00021 #include "cpx.hh"
00022 #include "avro/Encoder.hh"
00023 #include "avro/Decoder.hh"
00024 #include "avro/ValidSchema.hh"
00025 #include "avro/Compiler.hh"
00026 #include "avro/DataFile.hh"
00027
00028
00029 avro::ValidSchema loadSchema(const char* filename)
00030 {
00031     std::ifstream ifs(filename);
00032     avro::ValidSchema result;
00033     avro::compileJsonSchema(ifs, result);
00034     return result;
00035 }
00036
00037 int
00038 main()
00039 {
00040     avro::ValidSchema cpxSchema = loadSchema("cpx.json");
00041
00042     {
00043         avro::DataFileWriter<c::cpx> dfw("test.bin", cpxSchema);
00044         c::cpx c1;
00045         for (int i = 0; i < 100; i++) {
00046             c1.re = i * 100;
00047             c1.im = i + 100;
00048             dfw.write(c1);
00049         }
00050         dfw.close();
00051     }
00052
00053     {
00054         avro::DataFileReader<c::cpx> dfr("test.bin", cpxSchema);
00055         c::cpx c2;
00056         while (dfr.read(c2)) {
00057             std::cout << '(' << c2.re << ", " << c2.im << ')' << std::endl;
00058         }
00059     }
00060     return 0;
00061 }
00062


NOTES
----------------------------------------------

Use Thrift TFramedTransport, TTransport, TSocket for reading and writting to a socket

Eclipse, WindowsBuilder issue
----------------------------------------------

$ export SWT_GTK3=0
$ eclipse &


HOST & PORTS
----------------------------------------------

m_c_url : localhost,
m_c_wui : 9001
m_c: 9000
m_c pub/sub: 9001


mcs_url : localhost,
mcs_port : 9030,
mcs_subscriber: 9001
mcs wui: 9031

tm archive_url : localhost,
tm_archive_port : 9034,

hktm_processor_url : localhost,
hktm_processor_port : 9032,

tc_processor_url : localhost,
tc_processor_port : 9033,


fds_url : localhost,
fds_port : 9010,
fds_wui : 9011

gs_manager_url : localhost,
gs_manager_port : 9020,
gs_manager wui: 9021

tools_url : localhost,
tools_port : 9040,
tools_wui : 9041


Boost Serial Port
-------------------------------------------------

serial_port port(my_io_service, name);

where name is something like "COM1" on Windows, and "/dev/ttyS0" on POSIX platforms.



GNU Radio
-------------------------------------------------

Install GNU Radio
Install gr-satellites from Daniel Estevez

mkdir build
cd build
cmake ..
make
sudo make install
sudo ldconfig


Install libfec
Use gr-frontends from Daniel Estevez fo stream audio


Eclispe
--------------------------------------------------
Missing native libraries.
Add native location to the library in the Build Path
Select the library. Expand id
Edit native location of library


Events & Publish Event
---------------------------------------------------
This method: 
   void M_CModuleManager::publishMessage(const ServerMessage &inMessage)
   
publishes an Event in the Pub-Sub socket
It receives the Event type and adds the prefix "EVT:"

In order to subscribe to events:
// Events are prefixed with "EVT:"

eventId = EVENT_PREFIX + to_string( static_cast<int>(EventTypeEnum::EVT_NEW_RAW_FRAME));
inSubscriber->subscribe(eventId);


The data of an Event is a normal message; I.e. msg_get_layer or any component of the data model

SQLite
---------------------------------
exec() returns the number of affected rows
bind() starts from 1


Compile with CodeLite
---------------------------------
codelite-make -w cubegs.workspace -p Import_Database -c Debug -e -d build


alberto@lp-toshiba ~/Documents/01_gs4cubesat $ codelite-make
The value for the option 'w (or workspace)' must be specified.
Usage: codelite-make [-h] -w <str> -c <str> [-d <str>] [-p <str>] [-v] [-e] [-s <str>]
  -h, --help           	show this help message
  -w, --workspace=<str>	CodeLite workspace file
  -c, --config=<str>   	Workspace configuration name to use
  -d, --command=<str>  	Which command to run? possible values are: build, clean or rebuild. The default is to build
  -p, --project=<str>  	Project to build, if non given CodeLite will build the active project as defined in the workspace
  -v, --verbose        	Run in verbose mode and print all log lines to the stdout/stderr
  -e, --execute        	Instead of printing the command line, execute it
  -s, --settings=<str> 	The full path of the build_settings.xml file.

By default, CodeLite-make will load the compiler definitions from
%appdata%\CodeLite\config\build_settings.xml (or the equivalent path on
Unix systems). Passing -s|--settings will override the default search
location
A makefile generator based on codelite's workspace


ajfg: Apparently Config=Debug, Release

Compile Boost
-----------------------------------

./b2 --build-type=minimal
sudo ./b2 install

To reconfigure the build;

./b2 --reconfigure



Add a new message
----------------------------------

1 - Create the JSON file; msg_xxxx.json
2 - Add to "AvroTypes.json"
3 - Compile "AvroTypes.json"

4 - Add new code to OperationCodeEnum.h
5 - Create message handler in C++; XXXXXMessage.h, XXXXXMessage.cpp
5.1 - Add to XXXFactoryMessage.h

6 - Create links; ./create_links.sh
    Review project directory
6.1 - Compile java messages; ./compile.java.sh
7 - Add OperationCode to EnumOperationCode in class; EnumOperationCode.java
8 - Create jar GsCommon.jar

9 - Use the message


Spawn a process
----------------------------------

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

extern char **environ;

void run_cmd(char *cmd)
{
    pid_t pid;
    char *argv[] = {"sh", "-c", cmd, NULL};
    int status;
    printf("Run command: %s\n", cmd);
    status = posix_spawn(&pid, "/bin/sh", NULL, NULL, argv, environ);
    if (status == 0) {
        printf("Child pid: %i\n", pid);
        if (waitpid(pid, &status, 0) != -1) {
            printf("Child exited with status %i\n", status);
        } else {
            perror("waitpid");
        }
    } else {
        printf("posix_spawn: %s\n", strerror(status));
    }
}

int main(int argc, char* argv[])
{
    run_cmd(argv[1]);
    return 0;
}


Mixing C++ and Fortran
----------------------------------

testC.cpp 	

#include <iostream>

using namespace std;

extern"C" {
void fortfunc_(int *ii, float *ff);
}

main()
{

   int ii=5;
   float ff=5.5;

   fortfunc_(&ii, &ff);

   return 0;
}
                  
testF.f


subroutine fortfunc(ii,ff)
      integer ii
      real*4  ff

      write(6,100) ii, ff
 100  format('ii=',i2,' ff=',f6.3)

      return
      end
      
      
Compile:
f77 -c testF.f
g++ -c testC.cpp
g++ -o test testF.o testC.o -lg2c

Run:
$ ./testii= 5 ff= 5.500




FORTRAN program calling a C function:

testF.f 	

      program test

      integer ii, jj, kk
      common/ijk/ ii, jj, kk
      real*8  ff
      character*32 cc

      ii = 2
      jj = 3
      kk = 4
      ff = 9.0567
      cc = 'Example of a character string'

      write(6,10) ii, ff
10    format('ii= ',i2,' ff= ',f10.4)

      call abc(ii)

      write(6,20) ii
20    format('ii= ',i2)

      write(6,30) ii, jj, kk

      call doubleIJK(cc)

      write(6,30) ii, jj, kk
30    format('ii= ',i2,' jj= ', i2, ' kk= ', i2)

      write(6, 40) cc
40    format(a32)

      stop
      end

      subroutine abc(jj)
      jj = jj * 2
      return
      end


testC.c

#include <stdio.h>

extern struct
{
   int ii, jj, kk;
} ijk_;

int doubleijk_(char *cc, int ll)
{
   cc[ll--] = '\0';  // NULL terminate the string

   printf("From doubleIJK: %s\n",cc);

   ijk_.ii *=2;
   ijk_.jj *=2;
   ijk_.kk *=2;

   return(1);
}

Compile:

    gfortran -c testF.f
    gcc -c testC.c
    gfortran -o test testF.o testC.o

Note: If there is use of C/C++ standard libraries you may have to include the following linking arguments: -lc or -lstdc++

Run: ./test 

References:
https://people.sc.fsu.edu/~jburkardt/cpp_src/c++_calls_f90/c++_calls_f90.html

http://luthaf.fr/calling-c++-from-fortran.html

http://www.featflow.de/en/software/featflow2/tutorial/tutorial_lang.html


// Only Fortran 90 or above
// All arguments in FORTRAN are passed by reference and not by value. Thus C must pass FORTRAN arguments as a pointer.
//
//FORTRAN	C
//call subra( i, x)	subra_( int *i, float *x)


# Start of the makefile
# Defining variables
objects = global.o main.o function1.o subroutine1.o
f90comp = ifort
switch = -O3
# Makefile
execname: $(objects)
    $(f90comp) -o execname $(switch) $(objects)
global.mod: global.o global.f90
    $(f90comp) -c $(switch) global.f90
global.o: global.f90
    $(f90comp) -c $(switch) global.f90
main.o: global.mod main.f90
    $(f90comp) -c $(switch) main.f90
function1.o: global.mod function1.f90
    $(f90comp) -c $(switch) function1.f90
%.o: %.f90
    $(f90comp) -c $(switch) $<
# Cleaning everything
clean:
    rm global.mod 
    rm $(objects)
# End of the makefile



# compiler
FC := /usr/local/bin/gfortran

# compile flags
FCFLAGS = -g -c -Wall -Wextra -Wconversion -Og -pedantic -fcheck=bounds -fmax-errors=5
# link flags
FLFLAGS =

# source files and objects
SRCS = $(patsubst %.f08, %.o, $(wildcard *.f08))

# program name
PROGRAM = a.out

all: $(PROGRAM)

$(PROGRAM): $(SRCS)
    $(FC) $(FLFLAGS) -o $@ $^

%.mod: %.f08
    $(FC) $(FCFLAGS) -o $@ $<

%.o: %.f08
    $(FC) $(FCFLAGS) -o $@ $<

clean:
    rm -f *.o *.mod
    
    
    
    
# Find all source files, create a list of corresponding object files
SRCS=$(wildcard *.f08)
OBJS=$(patsubst %.f08,%.o,$(SRCS))

# Ditto for mods (They will be in both lists)
MODS=$(wildcard mod*.f08)
MOD_OBJS=$(patsubst %.f08,%.o,$(MODS))

# Compiler/Linker settings
FC = gfortran
FLFLAGS = -g
FCFLAGS = -g -c -Wall -Wextra -Wconversion -Og -pedantic -fcheck=bounds -fmax-errors=5
PROGRAM = characterize
PRG_OBJ = $(PROGRAM).o

# make without parameters will make first target found.
default : $(PROGRAM)

# Compiler steps for all objects
$(OBJS) : %.o : %.f08
    $(FC) $(FCFLAGS) -o $@ $<

# Linker
$(PROGRAM) : $(OBJS)
    $(FC) $(FLFLAGS) -o $@ $^

# If something doesn't work right, have a 'make debug' to 
# show what each variable contains.
debug:
    @echo "SRCS = $(SRCS)"
    @echo "OBJS = $(OBJS)"
    @echo "MODS = $(MODS)"
    @echo "MOD_OBJS = $(MOD_OBJS)"
    @echo "PROGRAM = $(PROGRAM)"
    @echo "PRG_OBJ = $(PRG_OBJ)"

clean:
    rm -rf $(OBJS) $(PROGRAM) $(patsubst %.o,%.mod,$(MOD_OBJS))

.PHONY: debug default clean

# Dependencies

# Main program depends on all modules
$(PRG_OBJ) : $(MOD_OBJS)

# Blocks and allocations depends on shared
mod_blocks.o mod_allocations.o : mod_shared.o


Mixed things
----------------------------------
std::chrono::seconds(5000)


HTTP 
----------------------------------

curl -v --get "http://127.0.0.1:10000"
curl -v --get "http://localhost:10000"



CppRest (Casablanca)
-----------------------------------
//auto tmpMethod = request.method();
   
//   if (tmpMethod
//   
//   DAT(GET,              _XPLATSTR("GET"))
//DAT(POST,             _XPLATSTR("POST"))
//DAT(PUT,              _XPLATSTR("PUT"))
//DAT(DEL,              _XPLATSTR("DELETE"))

//auto path = requestPath(message);
//  if (!path.empty()) {
//     if (path[0] == “service” && path[1] == “test”) {
//        auto response = json::value::object();
//        response[“version”] = json::value::string(“0.1.1”);
//        response[“status”] = json::value::string(“ready!”);
//        message.reply(status_codes::OK, response);
//     }
//  }
//  message.reply(status_codes::NotFound);
 
//   request
//      .extract_json()
//      .then([&answer, &action](pplx::task<json::value> task) {
//         try
//         {
//            auto  jvalue = task.get();
// 
//            if (!jvalue.is_null())
//            {
//               action(jvalue, answer);
//            }
//         }
//         catch (http_exception const & e)
//         {
//            wcout << e.what() << endl;
//         }
//      })
//      .wait();


















///============================================================================
///============================================================================
    OLD DO NOT USE
///============================================================================
///============================================================================




Qpid broker
------------------------------------------------

# No SASL authentication
$ qpidd --daemon  --auth no

$ qpidd --quit


Create user SASL2 (as root), realm QPID

[root@localhost Installation]# saslpasswd2 -f /var/lib/qpidd/qpidd.sasldb -u QPID test01
Password:
Again (for verification):
[root@localhost Installation]#

test01/test01


List of queues;

broker/mcs
broker/fds
broker/m_c
broker/tools

List of exchanges;


- Open a connection for each queue or topic at start up of the component
- Close the connection during the shutdown of the component
- Keep a map of connections per target component. To be created when the QpidIF object is created.


QPID Send & Receive
-----------------------------------------------------------

$ qpid-send -a "mcs" --content-string "xsdsfds" --subject message_code
$ qpid-receive -a mcs
xsdsfds

$ qpid-send -a "mcs" --content-string "primer mensaje" --subject 1
$ qpid-receive -a mcs
primer mensaje


spout = send a mesasge to a queue
drain = receive a message from a queue


Qpid Messages
-----------------------------------------------------------

Addresses
An address is the name of a message target or message source. The methods that create senders
and receivers require an address

address_string ::= <address> [ / <subject> ] [ ; <options> ]
options ::= { <key> : <value>, ... }


Nodes
An address resolves to a node. The Qpid Messaging API recognises two kinds of nodes: queues and
topics.

Queue
A queue stores each message until it has been received and acknowledged, and only one
receiver can receive a given message.

Exchange (Topic)
A topic immediately delivers a message to all eligible receivers.
If there are no eligible receivers, it discards the message. In the AMQP 0-10 implementation of the API,
queues map to AMQP queues, and topics map to AMQP exchanges.

Message

id               = message id. The message ID uniquely identifies a message within a messaging system.
user             = user name
to               = destination address
reply_to         = reply to address
correlation_id   = Set the ID for matching related messages
body             = Message body
subject          = message subject
content_type     = content type
content_encoding = how content is encoded
expiry_time      = expiration time
creation_time    = creation time

durable = The durable flag indicates that any parties taking responsibility for the message must durably store the content.

ttl = time to live. The TTL (time to live) for a message determines how long a message is considered live. When a message is held for retransmit, the TTL is decremented. Once the TTL reaches zero, the message is considered dead. Once a message is considered dead, it may be dropped.

priority = The priority of a message impacts ordering guarantees. Within a given ordered context, higher priority messages may jump ahead of lower priority messages.

first_acquirer = When set to true, the first acquirer flag for a message indicates that the recipient of the message is the first recipient to acquire the message, i.e. there have been no failed delivery attempts to other acquirers. Note that this does not mean the message has not been delivered to, but not acquired, by other recipients.

delivery_count = The delivery count field tracks how many attempts have been made to deliver a message

group_id = mesage group identifier

reply_to_group_id = reply-to group id

group_sequence = group sequence of a message. The group sequence of a message identifies the relative ordering of messages within a group. The default value for the group sequence of a message is zero.



Messages
========
SUBJECT        = Message type. I.e. LOGIN, LOGOUT, START UP
ID             = Message identifier. Filled by Qpid Proton or JMS
CORRELATION_ID = Identifier of the message to which this is related to
TO             = Name of queue or exchange
REPLY_TO       =
BODY           = Message encoded in AVRO


