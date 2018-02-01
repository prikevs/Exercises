
g_execution_time = require('utils').log_execution_time;

var fib = function fib(n) {
    if (n < 2) return n;
    return fib(n - 1) + fib(n - 2);
};

var timed_fib = log_execution_time(fib);

var sayHello = function sayHello() {
    console.log(Math.floor((new Date()).getTime() / 1000) + " - Hello world!");
};

var handleInput = function handleInput(data) {
    n = parseInt(data.toString());
    console.log('fib(' + n + ') = ' + timed_fib(n));
};

process.stdin.on('data', handleInput);
setInterval(sayHello, 3000);
