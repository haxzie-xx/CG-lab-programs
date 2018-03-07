# Computer Graphics Lab Programs

### Installation Instruction (Ubuntu/Linux)

- The first step is to install the development libraries of OpenGL/Glut in Ubuntu:
```
sudo apt-get install freeglut3 freeglut3-dev
```
- Clone the repository and CD over to [the test directory](https://github.com/haxzie/CG-lab-programs/test), execute the following command

```
$ gcc test.c -lGL -lGLU -lglut
$ ./a.out
```
if you are able to see a beutiful green window. You know you did it. Awesome!