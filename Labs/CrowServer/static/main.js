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
		
		var displayScore = "The "+ details["home_team"] + " beat the " + details["away_team"] + " by " + details["home_score"] + " to " + details["away_score"] + ". " ;
		
		$("#score-area").html(displayScore);
	});
}

function clickUpper(){
	var input = $("#upper-input").val();
	$.get("/upper", {word: input}, function(response){
		var cases = JSON.parse(response);
		
		var message = "Uppercase "+ cases["upper"] + " : Lowercase " + cases["lower"] +". " ;
		
		$("#upcase-area").html(message);
	});
}

