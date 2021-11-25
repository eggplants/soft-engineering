# pyenv install 3.11.0a2
# pyenv local 3.11.0a2
from typing import TypeVar, overload

T = TypeVar("T")


@overload
def print_number(n: int) -> None: ...

@overload
def print_number(n: float) -> None: ...

@overload
def print_number(n: object) -> None: ...

def print_number(n):
    if isinstance(n, int):
        print(f"{n} (int)")
    elif isinstance(n, float):
        print(f"{n} (float)")
    elif isinstance(n, object):
        print(f"{n} (not number)")


print_number(100)
print_number(1.5)
print_number("Hello!")
