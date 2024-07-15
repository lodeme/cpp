#pragma once

class Base {
  public:
    virtual ~Base();
};

class A: Base {};
class B: Base {};
class C: Base {};

Base* generate();
void identify(Base* p);
void identify(Base& p);

