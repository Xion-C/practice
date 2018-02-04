#ATTENTION

line 42: Pokemon(string n) : name(n) {}
it will compile, but use valgrind could dectect errors.
also, in visual studio, it could cause some problem

oooh i'm stupid
in copy constructor i wrote
    buf(new char(strlen(s.buf) + 1))
should be
    buf(new char[strlen(s.buf) + 1])
