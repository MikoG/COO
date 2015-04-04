/*
 * File:   main.cpp
 * Author: geth2k
 *
 * Created on 09 April 2013, 19:41
 */

#include "game.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    cout << *argv << endl;
    cout << "bool               " << sizeof(bool) << endl;
    cout << "short              " << sizeof(short) << endl;
    cout << "long               " << sizeof(long) << endl;
    cout << "char               " << sizeof(char) << endl;
    cout << "int                " << sizeof(int) << endl;
    cout << "float              " << sizeof(float) << endl;
    cout << "bool               " << sizeof(bool) << endl;
    cout << "game               " << sizeof(game) << endl;
    cout << "texset<float>      " << sizeof(sid::duplet<float>) << endl;
    cout << "sid::vbo           " << sizeof(sid::vbo) << endl;
    cout << "std::vector<short> " << sizeof(std::vector<short>) << endl;
    cout << "vertex3            " << sizeof(vertex3) << endl;
    cout << "std::string        " << sizeof(std::string) << endl;
    cout << "std::list<object*> " << sizeof(std::list<object*>) << endl;
    cout << "parent<object*>    " << sizeof(parent<object*>) << endl;
    cout << "child<object*>     " << sizeof(child<object*>) << endl;
    cout << "object             " << sizeof(object) << endl;
    cout << "sid::object_ingame " << sizeof(sid::object_ingame) << endl;
    cout << "control            " << sizeof(control) << endl;
    cout << "bits<uint>         " << sizeof(bits<uint>) << endl;
    cout << "__t_event_calls    " << sizeof(event_calls<object*>) << endl;
    cout << "interactive_object " << sizeof(sid::interactive_object) << endl;
    cout << "sid::t_vertset     " << sizeof(sid::t_vertset) << endl;
    cout << "sid::euclid        " << sizeof(sid::euclid) << endl;
    
    game* Game = new game();
    cout << Game->get_version() << endl;
    Game->run();
    delete Game;
    return 0;
}
