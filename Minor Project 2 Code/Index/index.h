const char MAIN_page[] PROGMEM = R"=====(
<html>

<head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="shortcut icon" href="https://media-exp1.licdn.com/dms/image/C4E0BAQEzb_74r1fLLg/company-logo_200_200/0/1614056149968?e=2147483647&v=beta&t=gDqZIWfV0Zr7yj4F0_nEFJdsbwQ4atwKBmbFMDUbcIg" type="image/x-icon">
    <script src="https://kit.fontawesome.com/afd317a279.js" crossorigin="anonymous"></script>
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <title>Minor Project : COVID PROTECTIVE ROBOT:- PHASE II</title>

    <style>
        html {
            font-family: Cairo;
            display: inline;
            margin: 0px auto;
            text-align: center;
            background-color: black;
            color: white;
        }

        button {
            background-color: #000000;
            border: white 1px;
            color: white;
            border-radius: 10px 10px;
            border-style: dotted;
            padding: 30px 80px;
            width: 100%;
            font-size: 15px;
            text-decoration: none;
            margin: 2px;
            font-weight: bold;
            cursor: pointer;
            height: auto;
            justify-content: space-between;
            transition: all 0.5s;
        }

        button:hover {
            background-color: #2EE59D;
            box-shadow: 0px 15px 20px rgba(46, 229, 157, 0.4);
            color: rgb(0, 0, 0);
            transform: translate(-7px, -7px);
        }

        .icon:hover {
            box-shadow: 0px 15px 20px rgba(46, 229, 157, 0.4);
            color: rgb(0, 0, 0);
        }

        .image {
            height: auto;
            position: relative;
            align-items: center;
            height: 400px;
            width: 90%;
            align-items: center;
            background-image: url(https://indoreinstitute.com/wp-content/uploads/2019/06/1.jpg);
            background-position: center;
            background-repeat: no-repeat;
            background-size: cover;
        }

        .small-underline {
            width: 50%;
            height: .1rem;
            background-color: #00ccff;
            margin: 0 auto 1rem auto;
        }

        .big-underline {
            width: 100%;
            height: 2px;
            background-color: #00ccff;
        }

        .line {
            width: 300px;
            height: 1px;
            border: solid 1px white;
        }

        .te {
            font-size: 20px;
            color: #ff0000;
            background-color: #000000;
            width: 300px; 
            text-decoration: none; 
            color: #e65715; 
            padding: 5px; 
            border: solid white 3px;
            border-radius: 0 20px ; 
            font-family: monospace; 
            transition: all 0.5s; 
            font-weight:1000;
            padding: 30px 30px;
            margin-top: 50px;
        }

        .button2 {
            background-color: #555555;
        }

        .icon {
            font-size: 70px;
            color: rgb(255, 255, 255);
            display: flex;
        }

        .lu {
            rotate: -45deg;
        }

        table {
            text-align: center;
            margin: 0;
            padding: 0;
        }
        .heading{
            color: black;
            font-family: monospace;
            font-style: italic;
            font-size: 25px;
        }
        .title{
            font-size: 25px;
            font-family:monospace;
        }
        .team-card{
            display: flex;
            flex-direction: row;
            flex-wrap: wrap;
            justify-content: space-evenly;
            transition: all 0.5s; 
        }

        .card-1{
            background-image:url(https://indoreinstitute.com/wp-content/uploads/2020/08/Dr.-Keshav-Patidar-300x289.jpg);
            width: 300px;
            height:300px;
            background-position:center;
            background-repeat: no-repeat;
            background-size: cover;
            margin-top: 30px;
            border-radius: 55px 20px;
            transition: all 0.5s;
        }
        .card-2{
            background-image: url(https://indoreinstitute.com/wp-content/uploads/2020/08/Mr.-Ankit-Jain-300x289.jpg);
            width: 300px;
            height:300px;
            background-position:center;
            background-repeat: no-repeat;
            background-size: cover;
            margin-top: 30px;
            border-radius: 55px 20px;
            transition: all 0.5s;
        }
        .card:hover{
                box-shadow: 0px 15px 20px rgba(255, 255, 255, 0.4);
            }

        .card-name{
            font-family:monospace;
            font-size: 25px;
            font-weight: bold;
            
        }

        @media only screen and (max-width: 800px) {
            body {
                background-color: rgba(241, 246, 248, 0.966);
                color: black;
            }

            button {
                padding: 20px 20px;
                background-color: white;
                color: rgb(255, 255, 255);
            }

            .icon {
                font-size: 70px;
                color: rgb(0, 0, 0);
                display: flex;
            }
            .te {
                font-size: 20px;
                color: #ff0000;
                background-color: #ffffff;
                width: 300px; 
                text-decoration: none; 
                color: #e65715; 
                padding: 5px; 
                border: solid black 3px;
                border-radius: 0 20px ; 
                font-family: monospace; 
                transition: all 0.5s; 
                font-weight:1000;
                padding: 30px 30px;
                margin-top: 50px;
             }

            button:hover {

                box-shadow: 0px 15px 20px rgba(0, 0, 0, 0.4);
                color: rgb(255, 255, 255);
                transform: translate(-7px, -7px);
                background-color: #00e1ff9b;
            }
            .te:hover{
                color: black;
                border-color:rgba(255, 255, 255, 0.616) ;
            }
            .card:hover{
                box-shadow: 0px 15px 20px rgba(0, 0, 0, 0.4);
            }
        }
    </style>
</head>

<body>
    <center>

        <table class=tablea>
            <tr>
                <td><a href="#"><button><i class="fa-solid fa-chevron-up icon lu"></i></button></a></td>
                <td><a href="#"><button><i class="fa-solid fa-chevron-up icon"></i></button></a></td>
                <td><a href="#"><button><i class="fa-solid fa-chevron-right icon lu"></i></button></a></td>
            </tr>
            <tr>
                <td><a href="#"><button><i class="fa-solid fa-chevron-left icon"></i></button></a></td>
                <td><a href="#"><button><i class="fa-solid fa-circle-stop icon"></i></button></a></td>
                <td><a href="#"><button><i class="fa-solid fa-chevron-right icon"></i></button></a></td>
            </tr>
            <tr>
                <td><a href="#"><button><i class="fa-solid fa-chevron-left icon lu"></i></button></a></td>
                <td><a href="#"><button><i class="fa-solid fa-chevron-down icon"></i></button></a></td>
                <td><a href="#"><button><i class="fa-solid fa-chevron-down icon lu"></i></button></a>
                <td>
            </tr>
        </table>
        <br>
        <a href="#"><button class="te">TEMPERATURE</button></a>

        <br>
        <h2 class="heading">Department of Electronics & Communication Engineering</h2>
        <br>

        <div class="image"></div>
        <br>
        <br>
        <br>
        <div class="underline">
            <div class="big-underline"></div>
            <br>
            <div class="small-underline"></div>
        </div>
        <h3 class="title">Minor Project : COVID PROTECTIVE ROBOT:- PHASE II</h3>
        <div class="underline">
            <div class="small-underline"></div>
            <div class="big-underline"></div>
        </div>
        <h2>Faculties</h2>
        <div class="team-card">
            <h2></h2>
            <div class="photo-1">
                <div class="card-1 card"></div>
                <p class="card-name">Keshav Patidar</p>
            </div>
            <div class="photo-2">
                <div class="card-2 card"></div>
                <p class="card-name">Ankit Jain</p>
            </div>
        </div>
        <h1>Result</h1>
        <br>
        <br>
        <center>
            <script>
                let btn = document.querySelector('button');
                let result = document.querySelector('h1');
                document.body.addEventListener('keydown', (e) =>{
                    if(e.key=='a'||e.key=='4')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/left";
                    }
                    if(e.key=='w'||e.key=='8')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/forward";
                    }
                    if(e.key=='d'||e.key=='6')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/right";
                    }
                    if(e.key=='s'||e.key=='5')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/stp";
                    }
                    if(e.key=='x'||e.key=='2')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/reverse";
                    }
                    if(e.key=='q'||e.key=='7')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/frwl";
                    }
                    if(e.key=='e'||e.key=='9')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/frwr";
                    }
                    if(e.key=='z'||e.key=='1')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/rwl";
                    }
                    if(e.key=='c'||e.key=='3')
                    {
                        result.innerText= "Enter Key Pressed";
                        window.location.href="/rwr";
                    }
                })
            </script>
</body>
</html>
)=====";