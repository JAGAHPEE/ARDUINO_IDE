const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Grand Hotel</title>
    <script src="https://kit.fontawesome.com/afd317a279.js" crossorigin="anonymous"></script>
    <link href="https://fonts.googleapis.com/icon?family=Material+Icons" rel="stylesheet">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link
        href="https://fonts.googleapis.com/css2?family=Montserrat:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap"
        rel="stylesheet">
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link
        href="https://fonts.googleapis.com/css2?family=Josefin+Sans:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;1,100;1,200;1,300;1,400;1,500;1,600;1,700&family=Montserrat:ital,wght@0,100;0,200;0,300;0,400;0,500;0,600;0,700;0,800;0,900;1,100;1,200;1,300;1,400;1,500;1,600;1,700;1,800;1,900&display=swap"
        rel="stylesheet">
    <link rel="icon" href="35img/Logo.png">
    <link rel="stylesheet" href="35.css">
    <style>
    html{
font-size: 62.5%;
box-sizing: border-box;

}
body{
    margin: 0;
}
/* 10/16=0.625*100=62.5% */
/* p{
    font-size: 30px;
    margin: 0;
    padding: 0;
    font-family: 'Montserrat', sans-serif;
} */
/* end of comman style */


/* navbar */

/*  side bar */
.sidebar{
    margin-top: 0;
    width: 8rem;
    height: 100%;
    background-color: #eee;
    position: fixed;
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    align-items: center;
    z-index: 10;

}
.menu-icon{
    /* width: 2rem;
    height: 2rem;
    background-color: #222;
 */
    cursor: pointer;
}
.line{
    height: .2rem;
    width: 2.5rem;
    background-color: #222;
    margin-bottom: .6rem;
    margin-top: 1rem;
}
.line-1,.line-3
{
    width: 1.8rem;
    transition: all 0.5s;
}
.menu-icon:hover .line{
    width: 2.5rem;
}

.social-icons-list{
    list-style: none;
    padding: 0;
    height: 25rem;
    display: flex;
    flex-direction: column;
    justify-content: space-evenly;
    align-items: center;
}
.social-link{
    font-size: 2rem;
    color: #777;
    transition: 0.3s color;
}
.social-link:hover{
    color: #deaa86;
}
.year p{
    margin-bottom: 1rem;
    font-size: 1.5rem;
    color: #555;
}
/* end of side bar */
/* Navigation */
.navigation{
    /* margin-left: 8rem; */
    left: -32rem;
    position: fixed;
    width: 40rem;
    height: 100%;
    background:linear-gradient(to top,rgb(34,34,41,1),rgb(34,34,41,0.8)) ,url(https://www.berjayahotel.com/sites/default/files/colombo_2.jpg) center no-repeat;
    background-size: cover;
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    align-items: center;
    transition: left 0.8s cubic-bezier(1,0,0,1);
    
}
.navigation-heading{
    font-family: 'Josefin Sans',sans-serif;
    font-size: 3.5rem;
    font-weight: 300;
    letter-spacing: .2rem;
    color: #deaa86;
    text-align: center;
}
.navigation-search{
    position: relative;
}
.navigation-search-input{
    padding: 1rem 2rem;
    width: 30rem;
    background-color: rgba(0,0,0,0.3);
    font-family: 'Josefin Sans',sans-serif;
    font-size: 1.6rem;
    color: #deaa86;
    letter-spacing: .1rem;
    outline: none;
    border: 0.1rem solid #555;
    border-radius: 10rem;
    transition: background-color 0.2s ;

}
.navigation-search-input:focus{
    background-color: rgba(0,0,0,0.1);
    
}
.navigation-search-btn{
    border: none;
    background-color: transparent;
    color: #deaa86;
    font-size: 1.7rem;
    position: absolute;
    top: 1rem;
    right: 1rem;
    cursor: pointer;
}
.navigation-search-btn:focus{
    outline: none;
}
.navigation-list{
    list-style: none;
    padding: 0;
    height: 28rem;
    display: flex;
    flex-direction: column;
    justify-content: space-between;
    align-items: center;
}
.navigation-link{
    color: #fff;
    letter-spacing: 1rem;
    font-size: 1.6rem;
    font-weight: 400;
    text-transform: uppercase;
    text-decoration: none;
    transition: color 0.5s;

}
.navigation-item{
    position: relative;
}
.navigation-link::before{
    content: "";
    width: 0rem;
    height: .1rem;
    background-color: #deaa86;
    position: absolute;
    top: 1rem;
    left: -4rem;
    /* transition: width 0.5s; */
    transition: width 0.5s cubic-bezier(1,0,0,1);
}
.navigation-link::after{
    content: "";
    width: 0rem;
    height: .1rem;
    background-color: #deaa86;
    position: absolute;
    top: 1rem;
    right: -4rem;
    /* transition: width 0.5s; */
    transition: width 0.5s cubic-bezier(1,0,0,1);
}
.navigation-link:hover{
    color: #deaa86;

}
.navigation-link:hover::after,
.navigation-link:hover::before{
    width: 3rem;
}
.copyright{
    color: #fff;
    margin-bottom: 1.5rem;
}


.checkbox:checked ~ .navigation{
    left: 8rem;
}


.checkbox:checked ~.sidebar .line-1 {
    transform: rotate(-405deg) translate(-5px,5px);
    width: 2.5rem;
}


.checkbox:checked ~.sidebar .line-2 {
    opacity: 0;
}


.checkbox:checked ~.sidebar .line-3 {
    transform: rotate(405deg) translate(-12px,-12px);
    width: 2.5rem;
}
/* ed of Navigation */
/* end of nav bar */    

/* Header */
.header{
    margin-left: 8rem;
    height: 100vh;
    background:linear-gradient(to top, rgba(0,0,0,0.6),rgba(0,0,0,0.5)),url(35img/headerimg.jpg) center no-repeat;
    background-size: cover;
}
.brand{
    display: flex;
    cursor: pointer;
}
.hotal-heading
{
    font-family: 'Josefin Sans',sans-serif;
    font-size: 2.7rem;
    font-weight: 400;
    color: #deaa86;
    letter-spacing: .2rem;
}
.banner{
    color: #ddd;
    height: 65rem;
    display: flex;
    flex-direction: column;
    align-items: center;
    justify-content: center;
}
.banner-heading{
    font-family: 'Josefin Sans',sans-serif;
    font-size: 7rem;
    font-weight: 400;
    margin-bottom: 0;
    animation: anim 2s;
}
.banner-paragraph{
    font-size: 3.5rem;
    font-weight: 300;
    animation: anim 1.5s .5s backwards;
}
.banner-button
{
    width: 21rem;
    padding: 1.2rem 2rem;
    font-size: 2rem;
    color: #333;
    letter-spacing: .1rem;
    border: none;
    border-radius: 10rem;
    outline: none;
    background: linear-gradient(to right, gold,goldenrod);
    cursor: pointer;animation: anim 1.5s 1s backwards;
    
}
.banner-button:hover{
    background: linear-gradient(to left, gold,goldenrod);
}
.banner-button:active{
    transform: translateY(.2rem);
}
@keyframes anim {
    0%{
        opacity: 0;
    }
    100%{
        opacity: 1;
    }
}
/* End of Header */


/* about us */
.about-us{
    margin-left: 8rem;
    display: flex;
    background-color: #ddd;
}
.about-us-content{
    flex: 0 1 50%;
    display: flex;
    flex-direction: column;
    justify-content: center;
    align-items: center;
    padding: 10rem;
    box-sizing: border-box;
}
.about-us-heading{
    font-family: 'Josefin Sans',sans-serif;
    font-size: 4rem;
    font-weight: 300;
    text-transform: uppercase;
    color: #555;
}
.small-underline
{
    width: 9rem;
    height:.1rem;
    background-color: #deaa86;
    margin: 0 auto 1rem auto;
    
}
.big-underline
{
    width: 20rem;
    height:.1rem;
    background-color: #deaa86;
}
.sub-heading{
    font-size: 3.5rem;
    font-weight: 300;
    letter-spacing: .2rem;
    color: #b85d1c;
}
.about-us-paragraph{
    font-size: 1.6rem;
    font-style: italic;
    font-weight: 300;
    text-align: center;
    margin-bottom: 5rem;
}


.about-us-btn{
    width: 15rem;
    padding: 0.7rem 0.5rem;
    font-family: 'Montserrat', sans-serif;
    font-size: 1.2rem;
    text-transform: uppercase;
    color: #b85d1c;
    background-color: transparent;
    border: .1rem solid #b85d1c;
    outline: none;
    cursor: pointer;
}
.btn-arrow{
    margin-left: .5rem;
    transition: margin-left .4s;
}

.about-us-btn:hover .btn-arrow{
    margin-left: 1.5rem;
}

.about-us-images{
    flex: 1 1;
    position: relative;
}
.image
{
    width: 32rem;
    position: absolute;
    top: 50%;
    left: 50%;
    box-shadow: 0 3rem 6rem rgba(0,0.0,.4);
    border-radius: .4rem;
    border: .2rem solid #b85d1c;
}
.image-1{
    transform: translate(-20%,-90%);
}
.image-2{
    transform: translate(-70%,-70%);
}
.image-3{
    transform: translate(-50%,-50%);
}
.image-4{
    transform: translate(-30%,-30%);
}

/* End of About Us */

/* common header */
.common-header{
    padding: 5rem;
    text-align: center;
    color: #b85d1c;
}
.small-underline
{
    width: 9rem;
    height:.1rem;
    margin: 0 auto 1rem auto;
    background-color: #deaa86;
    margin: 0 auto 1rem auto;
    
}
.big-underline
{
    width: 20rem;
    height:.1rem;
    margin: auto;
    background-color: #deaa86;
}
.common-heading{
    font-size: 4rem;
    font-weight: 300;
    letter-spacing: .2rem;
}

/* End of common header */


/* Rooms */

.rooms{
    margin-left: 8rem;
}

.rooms-cards-wrapper{
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
}
.room-card{
    width: 60rem;
    margin: 5rem;
    background-color: #15141b;
    box-shadow: 0 3rem 6rem rgba(0,0,0,0.3);
}
.room-img{
    width: 100%;
    height: 60%;
}
.room-card-content{
    color: #ddd;
    padding: 2rem;

}
.room-card-heading{
    margin: 0;
    font-size: 3rem;
    font-weight: 300;
}
.room-card-paragraph{
    font-size: 1.5rem;
    color: #777;
}
.room-price{
    font-size: 5rem;
    font-weight: 300;
    text-align: right;
    margin: 0;
}
.room-card-btn{
    width: 15rem;
    padding: 1.5rem 1rem;
    font-family: 'Montserrat', sans-serif;
    font-size: 1.2rem;
    text-transform: uppercase;
    color: #b85d1c;
    background-color: transparent;
    border: .1rem solid #b85d1c;
    border-radius: 10rem;
    outline: none;
    cursor: pointer;
}
.rooms-btn-wrapper{
    text-align: center;
}
.rooms-btn{
    width: 20rem;
    padding: 1.5rem 1rem;
    margin: 4rem 0;
    background-color: transparent;
    text-transform: uppercase;
    color: #b85d1c;
    border: .2rem solid #b85d1c;
    outline: none;
    cursor: pointer;
    box-shadow: 0 1.5rem 5rem rgba(0,0,0,0.2);
    transition: all .3s;
}
.rooms-btn:hover{
    background-color: #b85d1c;
    color: #ddd;

}
/* End of Rooms */

/* Customers */

/* Customers */
.customers{
    margin-left: 8rem;
    padding-bottom: 7rem;
    background-color: #15141C;
}
.customers-paragraph{
    font-size: 1.8rem;
    color: #ddd;
    width: 50%;
    margin: 2rem auto 8rem auto;
    text-align: center;
}
.customer-card{
    background-color: #ddd;
    width: 50rem;
    display: flex;
    margin-bottom: 5rem;
}
.card-2{
    margin-left: 2rem;
}
.customers-card-wrapper{
    display: flex;
    justify-content: space-evenly;
    
    flex-wrap: wrap;
}
.customer-image-wrapper{
    margin: auto 0;
    padding-bottom: 1.3rem;
    padding-top: 1.3rem;
    
}
.customer-image
{
    width: 20rem;
    margin-left: -1.3rem;
}
.customer-info{
    padding: 0 2rem;
}
.customer-fullName{
    font-size: 2rem;
    font-weight: 300;
    margin-bottom: 0;

}
.customer-paragraph-1{
    font-size: 1.2rem;
    font-style: italic;
    color: #b85d1c;
    text-align: justify;
}
.customer-paragraph-2{
    font-size: 1.3rem;
    font-style: italic;
    color: #b85d1c;
    text-align: justify;
}
/* End of Customers */

/* footer */

.footer
{
    margin-left: 8rem;

}
.main-part{
    display: flex;
    justify-content: space-between;
    background-color:#1e1e1e ;
    padding: 4rem;
}   
.hotel-heading{
    font-size: 2.5rem;
    font-weight: 300;
    color: goldenrod;
}

.footer-list
{
    list-style-type: none;
    padding: 0;

}
.footer-list-item
{
    margin-bottom: 2rem;
}
.footer-list-link
{
    font-size: 1.4rem;
    text-decoration: none;
    color: #ddd;
}
.contact p{
    font-size: 1.5rem;
    color: #ddd;
    margin-bottom: 4rem;
}
.footer-form
{
    display: flex;
}
.footer-input{
    padding: 1rem;
    width: 20rem;
    font-family:'Josefin Sans',sans-serif;
    font-size: 1.8rem;
    color: #444;
    outline: none;
}

.footer-btn{
    padding: 1rem;
    background-color: #b85d1c;
    color: #ddd;
    border: none;
}
.gallery{
   width: 45rem;
}
.image-wrapper{
    width: 12rem;
    margin: .4rem;
    overflow: hidden;
    
}
.footer-image{
    width: 100%;
    height: 100%;
    backface-visibility: hidden; /* It wil not  shake image */
    transition: all .5s;
}
.gallery-images{
    display:flex;
    flex-wrap: wrap;
}
.footer-image:hover{
    transform: scale(1.3);
    opacity: 1.5;
}
.creator-part
{
    display: flex;
    justify-content: space-between;
    align-items: center;
    background-color: #111;
    padding: 0 4rem;

}
.copyright-text
{
    font-size: 1.2rem;
    color: #aaa;
}
.text-right{
    font-size: 1.4rem;
    color: #ddd;

}
.text-right i{
    font-size: 2rem;
    margin: .5rem;
    color:tomato
}
.text-right span{
    color: gold;
}
/* end of footer */
    </style>
</head>

<body>
    <!-- nav bar -->
    <div class="navbar">
        <input type="checkbox" class="checkbox" id="click" hidden>
        <!-- sidebar -->
        <div class="sidebar">
            <label for="click">
                <div class="menu-icon">
                    <div class="line line-1"></div>
                    <div class="line line-2"></div>
                    <div class="line line-3"></div>
                </div>
            </label>

            <ul class="social-icons-list">
                <li>
                    <a href="#" class="social-link"><i class="fa-brands fa-facebook-f"></i></a>
                </li>
                <li>
                    <a href="#" class="social-link"><i class="fa-brands fa-twitter"></i></a>
                </li>
                <li>
                    <a href="#" class="social-link"><i class="fa-brands fa-google-plus-g"></i></a>
                </li>
                <li>
                    <a href="#" class="social-link"><i class="fa-brands fa-instagram"></i></a>
                </li>
            </ul>
            <div class="year">
                <p>2022</p>
            </div>
        </div>
        <!-- end of side bar -->

        <!-- Navigation -->
        <div class="navigation">
            <div class="navigation-header">
                <h1 class="navigation-heading">Grand Hotal</h1>
                <form action="" class="navigation-search">
                    <input type="text" name="" id="" class="navigation-search-input" placeholder="Search..">
                    <button class="navigation-search-btn">
                        <i class="fa-solid fa-magnifying-glass"></i>
                    </button>
                </form>
            </div>
            <ul class="navigation-list">
                <li class="navigation-item">
                    <a href="#" class="navigation-link">home</a>
                </li>
                <li class="navigation-item">
                    <a href="#" class="navigation-link">about us</a>
                </li>
                <li class="navigation-item">
                    <a href="#" class="navigation-link">Rooms</a>
                </li>
                <li class="navigation-item">
                    <a href="#" class="navigation-link">events</a>
                </li>
                <li class="navigation-item">
                    <a href="#" class="navigation-link">customers</a>
                </li>
                <li class="navigation-item">
                    <a href="#" class="navigation-link">contact</a>
                </li>
            </ul>
            <div class="copyright">
                <p>&copy;2022. Grand Hotel. All Rights Reserved </p>
            </div>
        </div>
        <!-- end of navigation -->
    </div>
    <!-- End of nav bar -->
    <!-- Header -->
    <header class="header">
        <div class="brand">
            <img src="35img/Logo.png" width="80px">
            <h3 class="hotal-heading">
                Grand Hotel
            </h3>
        </div>

        <div class="banner">
            <h1 class="banner-heading"> Welcome to Grand Hotel</h1>
            <p class="banner-paragraph">Make your life luxerious</p>
            <button class="banner-button">Check Out</button>
        </div>

    </header>
    <!-- End of Header -->
    <!-- About us -->
    <section class="about-us">
        <div class="about-us-content">

            <h1 class="about-us-heading">About Us</h1>

            <div class="underline">
                <div class="small-underline"></div>
                <div class="big-underline"></div>
            </div>

            <h3 class="sub-heading">Grand Hotel</h3>
            <p class="about-us-paragraph">Lorem ipsum dolor sit amet consectetur adipisicing elit. Ipsa cum
                libero dolore distinctio provident minus dicta unde, voluptatum at, facere corporis ducimus.
                Suscipit eius maxime fugiat nihil! Obcaecati, fugiat hic.</p>

            <button class="about-us-btn">
                Read More
                <i class="fa-solid fa-angles-right btn-arrow"></i>
            </button>
        </div>

        <div class="about-us-images">
            <img src="35img/inside/img1.jpg" class="image image-1">
            <img src="35img/inside/img2.jpg" class="image image-2">
            <img src="35img/inside/img3.jpg" class="image image-3">
            <img src="35img/inside/img4.jpg" class="image image-4">
        </div>

    </section>

    <!-- End of About us -->


    <!-- Rooms -->
    <section class="rooms">
        <div class="common-header">
            <h1 class="common-heading">
                Rooms in Grand Hotel
            </h1>
            <div class="underline">
                <div class="small-underline"></div>
                <div class="big-underline"></div>
            </div>
        </div>
        <div class="rooms-cards-wrapper">
            <div class="room-card">
                <img src="35img/inside/img2.jpg" class="room-img">
                <div class="room-card-content">
                    <h4 class="room-card-heading">Single Room</h4>
                    <p class="room-card-paragraph">Lorem ipsum dolor sit amet.</p>
                    <p class="room-price">$99.00</p>
                    <button class="room-card-btn">
                        Book Now
                        <i class="fa-solid fa-angles-right btn-arrow"></i>
                    </button>
                </div>
            </div>
            <div class="room-card">
                <img src="35img/inside/img3.jpg" class="room-img">
                <div class="room-card-content">
                    <h4 class="room-card-heading">Double Room</h4>
                    <p class="room-card-paragraph">Lorem ipsum dolor sit amet.</p>
                    <p class="room-price">$199.00</p>
                    <button class="room-card-btn">
                        Book Now
                        <i class="fa-solid fa-angles-right btn-arrow"></i>
                    </button>
                </div>
            </div>
            <div class="room-card">
                <img src="35img/inside/img4.jpg" class="room-img">
                <div class="room-card-content">
                    <h4 class="room-card-heading">Lux</h4>
                    <p class="room-card-paragraph">Lorem ipsum dolor sit amet.</p>
                    <p class="room-price">$299.00</p>
                    <button class="room-card-btn">
                        Book Now
                        <i class="fa-solid fa-angles-right btn-arrow"></i>
                    </button>
                </div>
            </div>
            <div class="room-card">
                <img src="35img/inside/img5.jpg" class="room-img">
                <div class="room-card-content">
                    <h4 class="room-card-heading">VIP</h4>
                    <p class="room-card-paragraph">Lorem ipsum dolor sit amet.</p>
                    <p class="room-price">$399.00</p>
                    <button class="room-card-btn">
                        Book Now
                        <i class="fa-solid fa-angles-right btn-arrow"></i>
                    </button>
                </div>
            </div>
        </div>
        <div class="rooms-btn-wrapper">
            <button class="rooms-btn">Check All Rooms</button>
        </div>

    </section>
    <!-- End of Rooms -->
    <!-- Customers -->
    <section class="customers">
        <div class="common-header">
            <h1 class="common-heading">
                Ous Customers
            </h1>
            <div class="underline">
                <div class="small-underline"></div>
                <div class="big-underline"></div>
            </div>
        </div>
        <p class="customers-paragraph">
            Lorem ipsum dolor sit amet consectetur adipisicing elit. Autem omnis repellat aperiam excepturi. Laboriosam
            minus vel consequuntur inventore consequatur quisquam?
        </p>
        <div class="customers-card-wrapper">
            <div class="customer-card">
                <div class="customer-image-wrapper">
                    <img src="35img/customer/s.jpeg" class="customer-image">
                </div>
                <div class="customer-info">
                    <h3 class="customer-fullName">Sandesh Kale</h3>
                    <p class="customer-paragraph-1">Happy Customers</p>
                    <p class="customer-paragraph-2">Lorem ipsum dolor sit amet, consectetur adipisicing elit. Pariatur,
                        ipsa. Laboriosam facere eius asperiores animi obcaecati? Similique, hic accusantium! Expedita
                        vitae vel esse similique numquam soluta? Unde error ratione quis.</p>
                </div>
            </div>
            <div class="customer-card card-2">
                <div class="customer-image-wrapper">
                    <img src="35img/customer/a.jpeg" class="customer-image">
                </div>
                <div class="customer-info">
                    <h3 class="customer-fullName">Arpit Kumar Sarathe</h3>
                    <p class="customer-paragraph-1">Happy Customers</p>
                    <p class="customer-paragraph-2">Lorem ipsum dolor sit, amet consectetur adipisicing elit. Nihil,
                        commodi ut possimus recusandae asperiores dolorem unde eveniet dignissimos, deserunt illum,
                        numquam cupiditate! Molestiae voluptatem illum ut. Nam sunt veritatis architecto.</p>
                </div>
            </div>
        </div>
    </section>
    <!-- End of Customers -->

    <!-- Footer -->

    <footer class="footer">
        <div class="main-part">
            <div class="footer-list-wrapper">
                <h3 class="hotel-heading">Grand Hotel</h3>
                <ul class="footer-list">
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            support@gmail.com
                        </a>
                    </li>
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            Palasia ,123
                        </a>
                    </li>
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            Tel:- +123 456 7890
                        </a>
                    </li>
                </ul>
            </div>

            <div class="footer-list-wrapper">
                <h3 class="hotel-heading">Explore</h3>
                <ul class="footer-list">
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            Home
                        </a>
                    </li>
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            About Us
                        </a>
                    </li>
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            Rooms
                        </a>
                    </li>
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            Events
                        </a>
                    </li>
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            Customers
                        </a>
                    </li>
                    <li class="footer-list-item">
                        <a href="" class="footer-list-link">
                            Contact
                        </a>
                    </li>
                </ul>
            </div>
            <div class="contact">
                <h3 class="hotel-heading">Contact</h3>
                <p>Sign up for News</p>
                <form class="footer-form">
                    <input type="text" class="footer-input" placeholder="Your Email">
                    <button class="footer-btn">Sign Up</button>
                </form>
            </div>
            <div class="gallery">
                <h3 class="hotel-heading">Gallery</h3>
                <div class="gallery-images">
                    <div class="image-wrapper">
                        <img src="35img/inside/img1.jpg" class="footer-image">
                    </div>


                    <div class="image-wrapper">
                        <img src="35img/inside/img2.jpg" class="footer-image">
                    </div>


                    <div class="image-wrapper">
                        <img src="35img/inside/img3.jpg" class="footer-image">
                    </div>


                    <div class="image-wrapper">
                        <img src="35img/inside/img4.jpg" class="footer-image">
                    </div>


                    <div class="image-wrapper">
                        <img src="35img/inside/img5.jpg" class="footer-image">
                    </div>


                    <div class="image-wrapper">
                        <img src="35img/inside/img3.jpg" class="footer-image">
                    </div>
                </div>
            </div>
        </div>

        </div>
        <div class="creator-part">
            <div class="copyright-text">
                <p>copyright &copy; 2022 Grand Hotel. All Rights Reserved</p>
            </div>
            <div class="text-right">
                <p>Made with <i class="fas fa-heart"></i>by <span>DJ</span></i></p>
            </div>
        </div>

    </footer>

    <!-- End of Footer -->
</body>
<script src="https://www.gstatic.com/dialogflow-console/fast/messenger/bootstrap.js?v=1"></script>
<df-messenger
  chat-icon="https:&#x2F;&#x2F;github.com&#x2F;JAGAHPEE&#x2F;testing&#x2F;blob&#x2F;a44cecc2d67c7dcc38b2ecfda4ae71e9d3ffc038&#x2F;logo-roar-bikes.png?raw=true"
  intent="WELCOME"
  chat-title="Mega"
  agent-id="19b63631-ce80-4de1-a862-9bd5fdee124d"
  language-code="en"
></df-messenger
>
</html>
)=====";