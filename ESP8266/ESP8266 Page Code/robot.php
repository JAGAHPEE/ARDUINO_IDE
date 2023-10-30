<!DOCTYPE html>
<html>
<head>
	<title>Controller RObot</title>
		<meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
</head>
<body style="background-image: url('https://wallpaperaccess.com/full/840326.jpg')">
	

			<br>
            <br>
            <div class="container" >
            	<div class="jumbotron" style="color:rgba(200,0,0);background-color: rgba(0,0,0,0.3);text-align:center;"><h3><b>Remote Control Car</b></h3></div>
            </div>
            <div class="container">
            	<div class="jumbotron" style="padding-top:20px;background-color: rgba(0,0,0,0.3);">
            <div class="row">
                <div class="col-xs-2"></div>
                <div class="col-xs-3"></div>
                <div class="col-xs-2" style="margin-left: 14px; font-size: 50px;"><button class="glyphicon glyphicon-circle-arrow-up" onclick="forward()"></button> </div>
                <div class="col-xs-2"></div>
                <div class="col-xs-2"></div>
            </div>
            <br>
            <br>
            <div class="row">
                <div class="col-xs-2"></div>
                <div class="col-xs-1"></div>
                <div class="col-xs-1" style="font-size: 50px;"><button class="glyphicon glyphicon-circle-arrow-left" onclick="left()"></button> </div>
                <div class="col-xs-1"></div>
                <div class="col-xs-1"><button class="btn btn-danger" style="margin-left:15px;height: 60px; width: 70px;" onclick="stop()">STOP</button></div>
                <div class="col-xs-2"></div>
                <div class="col-xs-1" style="margin-left: -60px; font-size: 50px;"><button class="glyphicon glyphicon-circle-arrow-right" onclick="right()"></button> </div>
                <div class="col-xs-2"></div>
            </div>
            <br>
            <br>
            <div class="row">
            <div class="col-xs-2"></div>
                <div class="col-xs-3"></div>
                <div class="col-xs-2" style="margin-left: 14px; font-size: 50px;"><button class="glyphicon glyphicon-circle-arrow-down" onclick="backward()"></button> </div>
                <div class="col-xs=2"></div>
                <div class="col-xs-2"></div>
            </div>
          
            </div>
        </div>
           <script type="text/javascript">
           	var id="<?php echo $_GET["deviceId"]?>";
           	var api="<?php echo $_GET["apiKey"]?>";
           	if(id==""||(api==""))
           	{
           		alert("invalid api and device id");
           		window.location = "http://localhost/proj_bolt/page.html";
           	}

           	function forward()
           	{
           		//var g1="https://cloud.boltiot.com/remote/"+api+"/digitalMultiWrite?pins=1,2,3,4&states=HIGH,LOW,HIGH,LOW&deviceName="+id;
           		var g1="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=1&state=HIGH&deviceName="+id;
           		var g2="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=2&state=LOW&deviceName="+id;
           		var g3="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=3&state=HIGH&deviceName="+id;
           		var g4="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=4&state=LOW&deviceName="+id;
				$.getJSON(g1,function(data,status){});
				$.getJSON(g2,function(data,status){});
				$.getJSON(g3,function(data,status){});
				$.getJSON(g4,function(data,status){});
				
				setTimeout(function(){},100000);
					
           	}

           	function backward()
           	{
           		//var g1="https://cloud.boltiot.com/remote/"+api+"/digitalMultiWrite?pins=1,2,3,4&states=LOW,HIGH,LOW,HIGH&deviceName="+id;
           		var g1="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=1&state=LOW&deviceName="+id;
           		var g2="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=2&state=HIGH&deviceName="+id;
           		var g3="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=3&state=LOW&deviceName="+id;
           		var g4="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=4&state=HIGH&deviceName="+id;
				$.getJSON(g1,function(data,status){});
				$.getJSON(g2,function(data,status){});
				$.getJSON(g3,function(data,status){});
				$.getJSON(g4,function(data,status){});
				
setTimeout(function(){},100000);
					
           	}
           	
           	function right()
           	{
           		var g1="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=1&state=HIGH&deviceName="+id;
           		var g2="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=2&state=LOW&deviceName="+id;
           		var g3="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=3&state=LOW&deviceName="+id;
           		var g4="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=4&state=LOW&deviceName="+id;
				$.getJSON(g1,function(data,status){});
				$.getJSON(g2,function(data,status){});
				$.getJSON(g3,function(data,status){});
				$.getJSON(g4,function(data,status){});
					setTimeout(function(){},100000);
           	}

           	function left()
           	{
           		var g1="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=1&state=LOW&deviceName="+id;
           		var g2="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=2&state=LOW&deviceName="+id;
           		var g3="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=3&state=HIGH&deviceName="+id;
           		var g4="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=4&state=LOW&deviceName="+id;
				$.getJSON(g1,function(data,status){if(!data.success){alert("Device Offline")}});
				$.getJSON(g2,function(data,status){});
				$.getJSON(g3,function(data,status){});
				$.getJSON(g4,function(data,status){});
				
				setTimeout(function(){},100000);
					
           	}

           	function stop()
           	{

           		var g1="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=1&state=LOW&deviceName="+id;
           		var g2="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=2&state=LOW&deviceName="+id;
           		var g3="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=3&state=LOW&deviceName="+id;
           		var g4="https://cloud.boltiot.com/remote/"+api+"/digitalWrite?pin=4&state=LOW&deviceName="+id;
				$.getJSON(g1,function(data,status){});
				$.getJSON(g2,function(data,status){});
				$.getJSON(g3,function(data,status){});
				$.getJSON(g4,function(data,status){});
				setTimeout(function(){},100000);
					
           	}



           </script>
</body>
</html>