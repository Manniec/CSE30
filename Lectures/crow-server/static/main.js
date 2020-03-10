function clickHello(){
	$.get("/hello", {}, function(response){
		$("#hello-area").html(response);
	});
}

function clickEcho(){
	var theWord = $("#echo-input").val();

	$.get("/echo", {word: theWord}, function(response){
		$("#echo-area").html(response);
	});
}

function clickScore(){
	$.get("/superbowl", {}, function(response){
		var details = JSON.parse(response);

		$("#home-team").html(details["home_team"]);
		$("#away-team").html(details["away_team"]);
		$("#home-score").html(details["home_score"]);
		$("#away-score").html(details["away_score"]);
	});
}

function clickSolve(){
	var a = $("#input-a").val();
	var b = $("#input-b").val();
	var c = $("#input-c").val();

	$.get("/quad", {"a" : a, "b" : b, "c" : c}, function(response){
		var solutions = JSON.parse(response);

		$("#x1").html("x1 = " + solutions["x1"]);
		$("#x2").html("x2 = " + solutions["x2"]);
	});
}

function clickCount(){
	var input = $("#input-freq").val();

	$.get("/count_freq", {"char_string" : input}, function(response){
		var result = JSON.parse(response);

		$("#freq-result").html("The letter " + String.fromCharCode(result["character"]) + " appears " + result["frequency"] + " times.");
	});
}
