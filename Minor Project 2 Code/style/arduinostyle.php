client.println("<!DOCTYPE HTML>");
client.println("<html>");
client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
client.println("<link rel=\"icon\" href=\"data:,\">");
client.println("<style>html { font-family: Cairo; display: inline; margin: 0px auto; text-align: center; background-color: ##FAF9F6; display:inline-block;}");
client.println("button { background-color: #006699; border: none; color: white; padding: 16px 40px;width:200px;");
client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
client.println(".image{width: auto; height:auto; position: relative;align-items:center;}");
client.println(".small-underline{width: 9rem;height:.1rem;background-color: #deaa86;margin: 0 auto 1rem auto;}");
client.println(".big-underline{width: 20rem;height:.1rem;background-color: #deaa86;}");
client.println(".button2 {background-color: #555555;}</style></head>");
client.println("<body>");
client.println("<center>");
client.println("<h1>Welcome to IIST Indore</h1>");
client.println("<br>");
client.println("<div class=\"image\"><img src=\"https://indoreinstitute.com/wp-content/uploads/2021/05/f1.png\"></div>");
client.println("<h1>Department of Electronics & Communication Engineering</h1>");
client.println("<br>");
client.println("<h2 class=\"title\">Minor Project : COVID PROTECTIVE ROBOT:- PHASE II</h2>");
client.println("<div class=\"underline\"><div class=\"small-underline\"></div><div class=\"big-underline\"></div></div>");
client.println("<br>");
client.println("<br>");
client.println("<a href=\"/stop\" width=\"70px\"><button>STOP</button></a>");
client.println("<a href=\"/forward\"\"><button>FORWARD</button></a><br/>");
client.println("<a href=\"/reverse\"\"><button>REVERSE</button></a>");
client.println("<a href=\"/left\"\"><button>LEFT</button></a><br/>");
client.println("<a href=\"/right\"\"><button>RIGHT</button></a><br/>");
client.println("<center>");
  client.println("</body>");
client.println("</html>");