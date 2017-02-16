$(document).ready(function() {
    $("#main-panel").load("server/server.htm");

	$("#nav-Forex").click(function() {
    	$("#main-panel").load("server/Forex.htm");
    });
});