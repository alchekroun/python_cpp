#include <pybind11/pybind11.h>

char version[]="2.0";

char const* getVersion() {
	return version;
}

char const* greet() {
  return "hello, world";
}

class Addition {
public:
	int operation(int x, int y) { return x + y; };
};

namespace py = pybind11;


PYBIND11_MODULE(hello_component,greetings)
{
  greetings.doc() = "greeting_object 2.0";
  greetings.def("greet", &greet, "a function saying hello");
  greetings.def("getVersion", &getVersion, "a function returning the version");

  py::class_<Addition>(greetings, "Addition")
	.def(py::init<>())
	.def("operation", &Addition::operation);
}
