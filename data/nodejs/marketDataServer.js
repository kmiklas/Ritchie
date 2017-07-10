// Exchange Listener
// Receives price ticks from the exchange
var d = new Date();
var s = "";
var exchange_addr = '192.168.1.109';
var exchange_port = 4950;
var dgram = require('dgram');
var server = dgram.createSocket('udp4');
server.on('listening', function () {
    var address = server.address();
    console.log('UDP Server listening on ' + address.address + ":" + address.port);
});
//server.bind(exchange_port, exchange_addr);
server.bind(exchange_port);

// *************************************
// Websocket Section
var websocket_addr = '192.168.1.109';
var websocket_port = 3000;

//var WebSocketServer = require('ws').Server, wss = new WebSocketServer({host:websocket_addr, port:websocket_port}), CLIENTS=[];
var WebSocketServer = require('ws').Server;
var wss = new WebSocketServer({host:websocket_addr, port:websocket_port, clientTracking:true});
var CLIENTS = [];

console.log('Websocket Listening to ' + websocket_addr + ':' + websocket_port + ' ...');
wss.on('connection', function(myWs, req) {
	const ip = req.connection.remoteAddress;
	s = "Connect,"+ip+','+d.getFullYear()+','+(d.getMonth()+1)+','+ d.getDate()+','+d.getHours()+','+d.getMinutes()+','+d.getSeconds()+','+d.getMilliseconds();
	console.log(s);
	CLIENTS.push(myWs);
	myWs.on('close', function(client) {
		CLIENTS.splice(CLIENTS.indexOf(client, 1))
		console.log("Client Disconnected");
	});
	myWs.on('error', function(client) {
		CLIENTS.splice(CLIENTS.indexOf(client, 1))
	});
});
server.on('message', function incoming(message, remote) {
	var price = message + ' ';
	for (var i=0; i<CLIENTS.length; ++i) {
		if(CLIENTS[i].readyState == CLIENTS[0].OPEN) {
			CLIENTS[i].send(price);
		}
	}
});