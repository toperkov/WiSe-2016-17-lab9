var app = require('express')(),
  http = require('http').Server(app),
  io = require('socket.io')(http),
  fs = require('fs'),
  sys = require('util'),
  exec = require('child_process').exec,
  child;

var SerialPort = require('serialport'),
   //SerialPort = serialport.SerialPort,
   portName = process.argv[2];
   
var myPort = new SerialPort(portName, {
   baudRate: 115200,
   parser: SerialPort.parsers.readline("\n")
 });   

myPort.on('open', showPortOpen);

 function showPortOpen() {
   console.log('port open. Data rate: ' + myPort.options.baudRate);
}

app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html');
});

io.sockets.on('connection', function(socket) {
    
        socket.on('disconnect', function(){
        console.log('user disconnected');
        });    

        myPort.on('data', function(data) {
            //console.log(data);
            
            if(data.indexOf("Temperature: ") > -1) {
                console.log(data.replace("Temperature: ", ""));
                var date = new Date().getTime();
                var temp = parseFloat(data.replace("Temperature: ", ""));
                socket.emit('tempUpdate', date, temp);
            }
            if(data.indexOf("Humidity: ") > -1) {
                console.log(data.replace("Humidity: ", ""));
                var date = new Date().getTime();
                var hum = (parseFloat(data.replace("Humidity: ", "")));
                //socket.emit('humUpdate', date, hum);
                //console.log(temp);
                //console.log(hum);
                socket.emit('humUpdate', date, hum);
            }
            if(data.indexOf("Light: ") > -1) {
                console.log(data.replace("Light: ", ""));
                var date = new Date().getTime();
                var light = (parseFloat(data.replace("Light: ", "")));
                //socket.emit('humUpdate', date, hum);
                //console.log(temp);
                //console.log(hum);
                socket.emit('lightUpdate', date, light);
            }
            
        });
});

http.listen(3000, function(){
  console.log('listening on *:3000');
});