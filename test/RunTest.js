#! /usr/bin/env node
var libSwigCNodejs = require('../swig/.libs/libSwigCNodejs');
let test = new libSwigCNodejs.Test;
test.run();
test.meetThread();
