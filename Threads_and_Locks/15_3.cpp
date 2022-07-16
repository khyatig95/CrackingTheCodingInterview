{\rtf1\ansi\ansicpg1252\cocoartf1348\cocoasubrtf170
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;\f1\fnil\fcharset0 Menlo-Bold;}
{\colortbl;\red255\green255\blue255;\red63\green127\blue95;\red127\green0\blue85;\red42\green0\blue255;
\red0\green80\blue50;\red0\green0\blue192;\red100\green40\blue128;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\deftab720
\pard\pardeftab720

\f0\fs24 \cf2 //Algorithm : 	Number all \ul chopsticks\ulnone . You first pick up the lower numbered \ul chopstick\ulnone . If the higher numbered\cf0 \
\cf2 //				\ul chopstick\ulnone  exists, pick up and eat. Else release the lowered \ul chopstick\ulnone  as well.\cf0 \
\cf2 //\cf0 \
\cf2 //				Avoids deadlock as all philosophers will first pick up left and then right except for the last.\cf0 \
\cf2 //				This breaks the chain. With this solution, a philosopher can never hold the larger \ul chopstick\cf0 \ulnone \
\cf2 // 				without holding the smaller one. This prevents the ability to have a cycle,\cf0 \
\cf2 // 				since a cycle means that a higher \ul chopstick\ulnone  would "point"to a lower one.\cf0 \
\
\pard\pardeftab720

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <mutex>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <thread>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <unistd.h>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <iostream>\cf0 \

\f1\b \cf3 #include
\f0\b0 \cf0  \cf4 <vector>\cf0 \

\f1\b \cf3 using
\f0\b0 \cf0  
\f1\b \cf3 namespace
\f0\b0 \cf0  std;\
\pard\pardeftab720
\cf2 //even\cf0 \
\cf2 //odd\cf0 \
\pard\pardeftab720

\f1\b \cf3 #define
\f0\b0 \cf0  numPhilosophers 5\
\
\

\f1\b \cf3 class
\f0\b0 \cf0  \cf5 Chopstick\cf0  \{\

\f1\b \cf3 private
\f0\b0 \cf0  :\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf6 id\cf0 ;\
	\cf5 mutex\cf0  \cf6 avail\cf0 ;\
\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	
\f1\b Chopstick
\f0\b0 (
\f1\b \cf3 int
\f0\b0 \cf0  val) \{\
		\cf6 id\cf0  = val;\
		\cf6 avail\cf0 .
\f1\b \cf7 unlock
\f0\b0 \cf0 ();\
	\}\
	
\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b pickUp
\f0\b0 () \{\
		
\f1\b \cf3 return
\f0\b0 \cf0 (\cf6 avail\cf0 .
\f1\b \cf7 try_lock
\f0\b0 \cf0 ()); \cf2 //Returns true if it is able to lock\cf0 \
	\}\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b putDown
\f0\b0 () \{ \cf2 //Only call putDown if it was able to pick up.\cf0 \
		\cf6 avail\cf0 .
\f1\b \cf7 unlock
\f0\b0 \cf0 ();\
	\}\
	
\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b getID
\f0\b0 () \{\
		
\f1\b \cf3 return
\f0\b0 \cf0 (\cf6 id\cf0 );\
	\}\
\};\
\

\f1\b \cf3 class
\f0\b0 \cf0  \cf5 Philosopher\cf0  \{\

\f1\b \cf3 private
\f0\b0 \cf0  :\
	\cf5 Chopstick\cf0 * \cf6 smaller\cf0 ;\
	\cf5 Chopstick\cf0 * \cf6 larger\cf0 ;\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf6 numBites\cf0 ;\
	
\f1\b \cf3 int
\f0\b0 \cf0  \cf6 id\cf0 ;\
\
	
\f1\b \cf3 bool
\f0\b0 \cf0  \cf6 doneEating\cf0 ;\
	
\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b pickUp
\f0\b0 ();\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b putDown
\f0\b0 ();\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b chew
\f0\b0 ();\
\

\f1\b \cf3 public
\f0\b0 \cf0  :\
	
\f1\b Philosopher
\f0\b0 (\cf5 Chopstick\cf0 * left, \cf5 Chopstick\cf0 * right, 
\f1\b \cf3 int
\f0\b0 \cf0  id);\
	
\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b eat
\f0\b0 ();\
	
\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b getID
\f0\b0 () \{\
		
\f1\b \cf3 return
\f0\b0 \cf0 (\cf6 id\cf0 );\
	\}\
\};\
\
\pard\pardeftab720

\f1\b \cf0 Philosopher :: Philosopher
\f0\b0 (\cf5 Chopstick\cf0 * left, \cf5 Chopstick\cf0 * right, 
\f1\b \cf3 int
\f0\b0 \cf0  index) \{\
	\cf6 id\cf0  = index;\
	
\f1\b \cf3 if
\f0\b0 \cf0  (left->getID() < right->getID()) \{\
		\cf6 smaller\cf0  = left;\
		\cf6 larger\cf0  = right;\
	\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
		\cf6 larger\cf0  = left;\
		\cf6 smaller\cf0  = right;\
	\}\
	\cf6 doneEating\cf0  = 
\f1\b \cf3 false
\f0\b0 \cf0 ;\
	\cf6 numBites\cf0  = 10;\
	cout << \cf4 "Create \ul Philospher\ulnone  "\cf0  << \cf6 id\cf0  << \cf4 " with smaller \ul chopstick\ulnone ="\cf0  << \cf6 smaller\cf0 ->getID() << \cf4 " and larger \ul chopstick\ulnone ="\cf0  << \cf6 larger\cf0 ->getID() << endl;\
\}\
\
\pard\pardeftab720

\f1\b \cf3 bool
\f0\b0 \cf0  
\f1\b Philosopher :: pickUp
\f0\b0 () \{\
	\cf2 //Try to pickup lower \ul chopstick\ulnone  first\cf0 \
	
\f1\b \cf3 if
\f0\b0 \cf0  (\cf6 smaller\cf0 ->pickUp()) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (\cf6 larger\cf0 ->pickUp()) \{\
			
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 true
\f0\b0 \cf0 ;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
			\cf6 smaller\cf0 ->putDown();\
			
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
		\}\
	\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
		
\f1\b \cf3 return
\f0\b0 \cf0  
\f1\b \cf3 false
\f0\b0 \cf0 ;\
	\}\
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b Philosopher :: putDown
\f0\b0 () \{\
	\cf2 //Put Down the larger \ul chopstick\ulnone  first\cf0 \
	\cf6 larger\cf0 ->putDown();\
	\cf6 smaller\cf0 ->putDown();\
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b Philosopher :: chew
\f0\b0 () \{\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<\cf6 numBites\cf0 ; i++)\
		
\f1\b \cf7 usleep
\f0\b0 \cf0 (1000);\
\}\
\

\f1\b \cf3 void
\f0\b0 \cf0  
\f1\b Philosopher :: eat
\f0\b0 () \{\
	
\f1\b \cf3 while
\f0\b0 \cf0 (!\cf6 doneEating\cf0 ) \{\
		
\f1\b \cf3 if
\f0\b0 \cf0  (pickUp()) \{\
			chew();\
			putDown();\
			\cf6 doneEating\cf0  = 
\f1\b \cf3 true
\f0\b0 \cf0 ;\
			cout << \cf4 "Finished eating for Philosopher "\cf0  << \cf6 id\cf0  << \cf4 " with smaller \ul chopstick\ulnone  "\cf0  << \cf6 smaller\cf0 ->getID() << \cf4 " and larger \ul chopstick\ulnone  "\cf0  << \cf6 larger\cf0 ->getID() << endl;\
		\} 
\f1\b \cf3 else
\f0\b0 \cf0  \{\
			\cf6 doneEating\cf0  = 
\f1\b \cf3 false
\f0\b0 \cf0 ;\
		\}\
	\}\
\}\
\

\f1\b \cf3 int
\f0\b0 \cf0  
\f1\b main
\f0\b0 () \{\
	\cf5 vector\cf0 <\cf5 thread\cf0 > threads;\
\
	\cf5 Philosopher\cf0 * p[numPhilosophers];\
	\cf5 Chopstick\cf0 *	c[numPhilosophers];\
\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<numPhilosophers; i++) \{\
		c[i] = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Chopstick\cf0 (i);\
	\}\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<numPhilosophers; i++) \{\
		
\f1\b \cf3 int
\f0\b0 \cf0  left_id = i;\
		
\f1\b \cf3 int
\f0\b0 \cf0  right_id = (i-1 < 0) ? (numPhilosophers-1) : i-1;\
		p[i] = 
\f1\b \cf3 new
\f0\b0 \cf0  \cf5 Philosopher\cf0 (c[left_id], c[right_id], i);\
	\}\
	\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<numPhilosophers; i++) \{\
		\cf5 thread\cf0  t(&\cf5 Philosopher\cf0 ::eat, p[i]);\
		threads.push_back(move(t));\
	\}\
\
	
\f1\b \cf3 for
\f0\b0 \cf0  (
\f1\b \cf3 int
\f0\b0 \cf0  i=0; i<numPhilosophers; i++) \{\
		threads[i].join();\
	\}\
	
\f1\b \cf3 return
\f0\b0 \cf0  0;\
\}\
}