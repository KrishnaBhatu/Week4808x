# Demonstration of Google Mock framework
[![Build Status](https://travis-ci.org/KrishnaBhatu/Week4808x.svg?branch=master)](https://travis-ci.org/KrishnaBhatu/Week4808x)
[![Coverage Status](https://coveralls.io/repos/github/KrishnaBhatu/Week4808x/badge.svg?branch=master)](https://coveralls.io/github/KrishnaBhatu/Week4808x?branch=master)
---
## Author
Krishna Suresh Bhatu [GitHub Link](https://github.com/KrishnaBhatu)

## Overview and changes
This branch demonstrates the basic implementation of the Google Mock framework.

Changes made to incorporate the Google Mock environment:
 * Made a new class (NewVal) which has a virtual method (checkResult). This class demonstrates the service providers or the API that are generally used in the programs. The function of this method is to check if the calculated velocity that we get after we apply the PID control is equal to the desired velocity. It returns a boolean flag.
 * In the PidController class, a new method(velWithAddAPI) is added which is made dependent on the new virtual method which is accesed by the object pointer. This represents the clients that use the services of APIs. It only prints that the Desired velocity is achieved if it gets a true flag from the service method((checkResult).

Now the following are the additions made in the test file to test the API using the mock class:
 * A mock class is made which acts as the substitute to the server class(API). 
```
class Mocktest : public NewVal {
 public:
  MOCK_METHOD2(checkResult, bool(double calVel, double desVel));
};
```
 Thus this is the mock class which only uses the methods that we are using for our application and the methods that we need to test. (In our program we only have one method but an API can have many methods and if our testing is dependent on the API then it becomes dependent on many libraries or expensive resources. So the mock class resuces these effects and makes the testing fast and free from uncertainties.
 * The the Test is made which will use the mock class which is as follows:
```
TEST(PidControllerTest, APITest) {
  Mocktest mockobj;
  EXPECT_CALL(mockobj, checkResult(_, _)).Times(AtLeast(1));
  PidController pidObj(&mockobj);
  EXPECT_FALSE(pidObj.velWithAddAPI(30.0, 40.0));
}
```
 Here, the object of mock class is used to test the method. Thus, this demonstrates the implementation of mock testing.
 
## Installation
To install the google  mock framework run the following command in your terminal.
```
sudo apt-get install -y google-mock
```

## Build Instructions
```
git clone -b GMock_Extra_Credit_Krishna https://github.com/KrishnaBhatu/Week4808x
cd <path to repository>
mkdir build
cd build
cmake ..
make 
```

## Run Test
Following is the command to run the test:
```
./test/cpp-test
```
We get the following result after running the test:
```
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from PidControllerTest
[ RUN      ] PidControllerTest.PIDAlgoTest
[       OK ] PidControllerTest.PIDAlgoTest (0 ms)
[ RUN      ] PidControllerTest.PIDinit
Class is destroyed
[       OK ] PidControllerTest.PIDinit (0 ms)
[ RUN      ] PidControllerTest.APITest
Desired Value is NOT Achieved
Class is destroyed
[       OK ] PidControllerTest.APITest (0 ms)
[----------] 3 tests from PidControllerTest (0 ms total)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 3 tests.
Class is destroyed

```

## Run Program
Following is the command to run the program
```
./app/shell-app
```
Note: The tuned values for Kp, Kd and Ki are (0.1,0.01,0.5) respectively. So, input them to get the desired results.


