function addLetter(letter){
	var curr = $("#display-word").html();

	if (curr == ""){
		curr = letter;
	}
	else {
		curr = curr + " " + letter;
	}

	$("#display-word").html(curr);
}

function resetInterface(){
	$("#btn1").prop("disabled",false);
	$("#btn2").prop("disabled",false);
	$("#btn3").prop("disabled",false);
	$("#btn4").prop("disabled",false);
	$("#btn5").prop("disabled",false);
	$("#btn6").prop("disabled",false);
	$("#btn7").prop("disabled",false);
	$("#btn8").prop("disabled",false);
	$("#btn9").prop("disabled",false);
	$("#display-word").html("");
}

$(document).ready(function(){//is opened as soon as you load the page
	$.get("/list", {}, function(response){ // makes request to list end point app.cpp
		var data = JSON.parse(response);
		var list = []

		for (var i in data){
			var letter = String.fromCharCode(parseInt(data[i]));
			list.push(letter);
		}

		$("#btn1").html(list[0]);
		$("#btn1").click(function(){ //once letter clicked disable it (only use a letter once)
			addLetter(list[0]); //makes letter appear in display above
			$(this).prop("disabled",true);
		});

		$("#btn2").html(list[1]);
		$("#btn2").click(function(){
			addLetter(list[1]);
			$(this).prop("disabled",true);
		});

		$("#btn3").html(list[2]);
		$("#btn3").click(function(){
			addLetter(list[2]);
			$(this).prop("disabled",true);
		});

		$("#btn4").html(list[3]);
		$("#btn4").click(function(){
			addLetter(list[3]);
			$(this).prop("disabled",true);
		});

		$("#btn5").html(list[4]);
		$("#btn5").click(function(){
			addLetter(list[4]);
			$(this).prop("disabled",true);
		});

		$("#btn6").html(list[5]);
		$("#btn6").click(function(){
			addLetter(list[5]);
			$(this).prop("disabled",true);
		});

		$("#btn7").html(list[6]);
		$("#btn7").click(function(){
			addLetter(list[6]);
			$(this).prop("disabled",true);
		});

		$("#btn8").html(list[7]);
		$("#btn8").click(function(){
			addLetter(list[7]);
			$(this).prop("disabled",true);
		});

		$("#btn9").html(list[8]);
		$("#btn9").click(function(){
			addLetter(list[8]);
			$(this).prop("disabled",true);
		});
	});

	$("#clearWord").click(function(){
		resetInterface();
	});

	$("#newGame").click(function(){
		resetInterface();
		$("#correct").html("");
	});

	$("#checkWord").click(function(){
		var attempt = $("#display-word").html(); 
		attempt = attempt.replace(/\s/g, ''); //removes spaces string concatination 

		$.get("/checkWord", {word: attempt}, function(response){ //checkWord end point (attempt=letters concatinated together)
			var answer = JSON.parse(response);
			var word = answer["word"]; //receive word
			var valid = answer["valid"]; //true or false is it valid?

			resetInterface();

			if (valid){ //if valid add word to list of correct words
				var curr = $("#correct").html();
				if (curr == ""){
					curr = word;
				}
				else{
					curr = curr + ", " + word;
				}
				$("#correct").html(curr);
			}

			console.log(answer);

		});
	});
});
