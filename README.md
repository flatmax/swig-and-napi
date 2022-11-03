# Project Foundations

This is a project foundation for C++ SWIG, node-addon-api (napi) and nodejs. It is based on autotools and lets you call C++ code from nodejs. It also lets you call javascript code (in the main nodejs thread) from a C++ thread.

# requirements

You will need node-addon-api. Install in /usr/local and link to /usr/local/include :

```
cd /usr/local
git clone git@github.com:nodejs/node-addon-api.git
cd include
ln -s ../node-addon-api
```

You will also need libnodejs and a recent version of swig installed on your system.

# Initial Setup

./autogen.sh

# configuring

./configure

# building

make

# running

```
cd test
./RunTest.js
```

# install

make install

# uninstall

make uninstall
