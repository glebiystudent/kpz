# Text Parser
First things first let's see how our project looks from the outside
![](https://raw.githubusercontent.com/glebiystudent/kpz/main/img/pic1.jpg)
Our focus is mainly going to be at the "src" folder, as it contains all the files that make our library, the "init.hpp" just inits the whole library and glues it together by including all the right parts here and there
- core/engine:
    - core.hpp - singleton wrapper to make the program run via lambda anonymous functions(specifically it's menu)
- core components:
    - filemanager.hpp - SRP-type class to load the files in the /bin/ folder and then proceeded to be used in the parser
    - parser.hpp - SRP-type class that parses the file and ensures the stability of /bin/ 
- objects: (used in the guide command with the idea of dynamic text changing)
    - comment.hpp - //comment
    - keyvalue.hpp - the main data field cell aka key:value pairs in the "config" files that we'll have
    - syntaxobject.hpp - Factory-type virtual class(^ inhereted from 


With that out the way we can now switch our focus to something less-technical
- bin folder
    - when the program runs and when a client/user/anyone boots it up the program automatically creates a /bin/ folder if its not created yet(in this folder we place our config files)
![](https://raw.githubusercontent.com/glebiystudent/kpz/main/img/pic4.jpg)

Now let's see how our program looks (finally..) ![](https://raw.githubusercontent.com/glebiystudent/kpz/main/img/pic2.jpg)
Now the user has to just follow a quick instruction, load -> extract -> do whatever. 
Let's pretend we loaded the files. This little box shows up right below our main menu providing a list of all available files right now
![](https://raw.githubusercontent.com/glebiystudent/kpz/main/img/pic3.jpg)
Now.. let's load something? And see the preview of what is in there..
![](https://raw.githubusercontent.com/glebiystudent/kpz/main/img/pic5.jpg)
But that's pretty boring, let's parse something!
![](https://raw.githubusercontent.com/glebiystudent/kpz/main/img/pic6.jpg)
And that might seem like the program just pasted [] here and there but it actually deduced it from a key:value pattern in the actual config file, here's how it looks without the parsing algorithm:
![](https://raw.githubusercontent.com/glebiystudent/kpz/main/img/pic7.jpg)
You see the last two with the ':' in between? That's our variables that are now stored in a big storage system in our class. Everything else, including comments and a random gibberish was utterly ignored by the program's filtering system