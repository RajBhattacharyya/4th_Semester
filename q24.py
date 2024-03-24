def computeLPSArray(pat):
    M = len(pat)
    lps = [0] * M
    length = 0
    i = 1

    while i < M:
        if pat[i] == pat[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def search(pat, txt):
    M = len(pat)
    N = len(txt)
    lps = computeLPSArray(pat)

    i = 0 # Index for txt[]
    j = 0 # Index for pat[]

    while i < N:
        if pat[j] == txt[i]:
            i += 1
            j += 1

        if j == M:
            print("Pattern found at index", i - j)
            j = lps[j - 1]

        elif i < N and pat[j] != txt[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1

# Driver program to test above function
txt = "AABAAACAAADAAABAABAA"
pat = "AABA"
search(pat, txt)
