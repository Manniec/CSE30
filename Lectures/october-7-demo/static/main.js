$(document).ready(function(){
	$("#intRepBtn").click(function(){
		var x = $("#intRepInput").val();

		$.get("/intRep", {"num": x}, function(response){
			var data = JSON.parse(response);

			if (data["valid"]){
				$("#byte1").html(data.hex[0]);
				$("#byte2").html(data.hex[1]);
				$("#byte3").html(data.hex[2]);
				$("#byte4").html(data.hex[3]);
			}
			else{
				alert("Invalid Input");
			}


		});

	});
});
