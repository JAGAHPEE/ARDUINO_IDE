const char MAIN_page[] PROGMEM = R"=====(
<html>

<head>
  <title>ESP32-CAM Robot</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body {
      font-family: Arial;
      text-align: center;
      margin: 0px auto;
      padding-top: 30px;
    }

    table {
      margin-left: auto;
      margin-right: auto;
    }

    td {
      padding: 8 px;
    }
body{
  
}
    .button {
      background:rgba(255, 166, 0, 0.911);
      border: none;
      color: rgb(0, 0, 0);
      padding: 10px 50px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 18px;
      margin: 6px 3px;
      cursor: pointer;
      -webkit-touch-callout: none;
      -webkit-user-select: none;
      -khtml-user-select: none;
      -moz-user-select: none;
      -ms-user-select: none;
      user-select: none;
      -webkit-tap-highlight-color: rgba(0, 0, 0, 0);
      border: solid black ;
      border-radius: 4px;
      justify-content: center;
      
      display:block ;
    }
    .table{
      background-color: aqua;
      border: 2px solid black;
      border-radius: 5px;
      
    }
  </style>
</head>

<body>
  <h1>WIFI ROBOT</h1>
  <table class="table">
    <tr >
      <td ></td>
      <td><a href="forward" class="button">Forward</a></td>
      <td> </td>
    </tr>
  
    <tr>
      
        <td><a href="left" class="button">Left</a></td>
      
        <td><a href="stop" class="button">Stop</a></td>
     
        <td><a href="right" class="button">Right</a></td>
      
    </tr>
    <tr >
      <td ></td>
      <td><a href="backward" class="button">Backward</a></td>
      <td> </td>
    </tr>
</body>
</html>
    )=====";