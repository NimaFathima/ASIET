import java.applet.Applet;
import java.awt.*;
import java.util.*;

public class PassingParametersApplet extends Applet {
    
    String name;
    int age;

    public void init() {
        name = getParameter("name");
        String ageStr = getParameter("age");
        
        if (ageStr != null) {
            try {
                age = Integer.parseInt(ageStr);
            } catch (NumberFormatException e) {
                age = 0;
            }
        } else {
            age = 0;
        }
    }

    public void paint(Graphics g) {
        g.drawString("Name: " + name, 20, 30);
        g.drawString("Age: " + age, 20, 50);
    }
}

/* HTML Code to Run the Applet
  <!DOCTYPE html>
<html>
    <head>
        <title>Passing Parameters to Applet</title>
    </head>
    <body>
        <h1>Java Applet with Parameters</h1>
        
        <applet code="PassingParametersApplet.class" width="300" height="150">
            <param name="name" value="John Doe">
            <param name="age" value="25">
        </applet>
        
    </body>
</html>
*/

/*OUTPUT:
Name: John Doe
Age: 25
*/
