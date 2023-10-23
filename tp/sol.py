def solve(doc):
    separatedList = doc.split("`")
    i = 1
    ans = ""

    def doCam(s):
        rs = "" + s[0].lower()
        for i in range(1, len(s)):
            if s[i] != "_":
                rs += s[i].lower()
            else:
                i += 1
                rs += s[i].upper()

        return rs

    for word in separatedList:
        if i % 2 == 0:
            new_list = word.split(" ")
            first = new_list[0]
            new_s = ""
            for a in new_list:
                if a.isupper() and "_" not in a:
                    if a is first:
                        new_s += a
                    else:
                        new_s += " " + a
                else:
                    if a is first:
                        new_s += doCam(a)
                    else:
                        new_s += " " + doCam(a)
            ans += "`" + new_s + "`"
        else:
            ans += word
        i += 1

    return ans


a = "This is a `function_name OKKK_hai_na CONSTANT` and `VARIABLE_NAME` example."
print(solve(a))
