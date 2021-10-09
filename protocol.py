from lark import Lark
from lark.exceptions import LarkError


def main():
    l = Lark('''
        start: message

        message : brightness "," inner_rotary "," outer_rotary "," btnsx1 "," btnsx2 "," btnsx3 "," btnsx4 "," btndx1 "," btndx2 "," btndx3

        brightness: "0" | INT

        inner_rotary: rotary_event
        outer_rotary: rotary_event

        btnsx1: button_event
        btnsx2: button_event
        btnsx3: button_event
        btnsx4: button_event
        btndx1: button_event
        btndx2: button_event
        btndx3: button_event

        rotary_event: "-1" | "0" | "1"
        button_event: "-1" | "0" | "1"

        %import common.INT
    ''')

    ok(lambda: l.parse("0,0,0,0,0,0,0,0,0,0"))       # OK
    ok(lambda: l.parse("956,0,0,0,0,0,0,0,0,0"))     # OK
    ok(lambda: l.parse("0,-1,0,0,1,0,0,0,1,-1"))     # OK
    ok(lambda: l.parse("-1,0,0,0,0,0,0,0,0,0"))      # NOT OK
    ok(lambda: l.parse("0,31,0,0,0,0,0,0,0,0"))      # NOT OK
    ok(lambda: l.parse("0,0,0,0,0,0,17,0,0,0"))      # NOT OK


def ok(f):
    try:
        f()
        print("OK")
    except LarkError:
        print("NOT OK")


if __name__ == "__main__":
    main()
