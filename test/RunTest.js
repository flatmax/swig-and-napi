#! /usr/bin/env node

// Node addon api - setup the callback
var libNapiNodejs = require('../swig/.libs/libNapiNodejs');
let fp = libNapiNodejs.start(function () {
    console.log("JavaScript callback called with arguments", Array.from(arguments));
}, 5);

// SWIG get our C++ and thread running
var libSwigCNodejs = require('../swig/.libs/libSwigCNodejs');
let test = new libSwigCNodejs.Test;
test.setFnPointer(fp); // tell swig the callback function pointer to execute
test.run(); // run the C++ thread in the SWIG module

// in the main thread, print out main every second
const id = setInterval(()=>console.log('main'),1000);
test.meetThread(); // wait for the C++ thread to exit
