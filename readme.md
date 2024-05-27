# Text Parser / Explanation / Design patterns
First things first let's see how our project looks from the outside
![](https://raw.githubusercontent.com/glebiystudent/kpz/main/img/pic1.jpg)
Our focus is mainly going to be at the "src" folder, as it contains all the files that make our library, the "init.hpp" just inits the whole library and glues it together by including all the right parts here and there
- core/engine:
    - core.hpp - singleton wrapper to make the program run via lambda anonymous functions(specifically it's menu) (singleton used to make a static-type program class that can and must be created only once to init the program)
- core components:
    - filemanager.hpp - SRP-type class to load the files in the /bin/ folder and then proceeded to be used in the parser
    - parser.hpp - SRP-type class that parses the file and ensures the stability of /bin/ (SRP is used to handle one responsibility)
- objects: (used in the guide command with the idea of dynamic text changing)
    - comment.hpp - //comment
    - keyvalue.hpp - the main data field cell aka key:value pairs in the "config" files that we'll have
    - syntaxobject.hpp - Factory-type virtual class(^ inhereted from these classes, Factory is used here to easily create and manage other possible-upcoming classes in the whole project)


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

## Programming Principles

### KISS
This principle is a very simple and straight-to-the-point one, just keep it simple so every other developer/co-worker would understand everything that is happening within the code structure and you yourself is able to fix/refactor issues way faster than if the code would've been complex and harsh to even look at

### DRY
This principle's main logic is to never repeat yourself more than two times, as this optimizes the code performance/readibility/speed-of-use and all sorts of good and neat things

### YAGNI
Don't implement something unless it is crucically necessary, this will avoid a lot of unnecessary code and useless piles of lines that are just slowing down the code and wasting everyone's elses time

### SoC
So what the name implies is that you split the concerns, what that means that you're splitting the code for different purposes making it way-way easier to read/run/fix/debug/anything, instead of having one enormous class that has thousands of lines of code you'd rather do five classes that are basically doing the same thing but splitting the first gigantic class making it much more easier to interact with code/developers/bracnhes

### Avoid Premature Optimization
Premature optimization is the root of all evil in programming. –Donald Knuth
Never optimize your code as soon as you start writing it, obviously, some kind of optimization(just a little bit!) while you are writing it may be good, but trying your best to make your code the best will actually do more harm than good, optimize it at the end, when everything's done, because you might be optimizing something that will ruin at the end and you'll have to do twice as much work as you needed to without this principle

