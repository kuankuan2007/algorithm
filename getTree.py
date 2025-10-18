import random
import subprocess
import io
import threading
import time
import os
from pathlib import Path
def runTest(id: int):
    START = 1
    END = random.randint(100, 10000)
    res: list[tuple[int, int]] = []
    for i in range(START + 1, END + 1):
        res.append((i, random.randint(START, i - 1)))
    inputText = (
        f"{END-START+1}\n"
        + "\n".join(f"{i[0]} {i[1]}" for i in res)
        + f"\n{random.randint(START,END)} {random.randint(START,END)}\n"
    )
    INPUT_FILE = Path(f"./temp/{id}.in")
    OUTPUT_FILE = Path(f"./temp/{id}.out")
    with open(INPUT_FILE, "w", encoding="utf-8") as f:
        f.write(inputText)
    try:
        with open(OUTPUT_FILE, "w", encoding="utf-8") as outF, open(INPUT_FILE, "r", encoding="utf-8") as inF:
            subprocess.run(
                "./p8655.exe", stdin=inF, stdout=outF, check=True
            )
    except subprocess.CalledProcessError as e:
        print(f"Error in test {id}: {e}")
        os._exit(1)
    with open(OUTPUT_FILE, "r", encoding="utf-8") as f:
        outputText = f.read()
    print(f"{id}:{outputText.replace('\n', '').strip()}\n",end="")
    INPUT_FILE.unlink(missing_ok=True)
    OUTPUT_FILE.unlink(missing_ok=True)

def threadRun(idStart: int):
    nowId=idStart
    while True:
        runTest(nowId)
        nowId+=threadNum

threadNum = 10

for i in range(0, threadNum):
    threading.Thread(target=threadRun, args=(i,), daemon=True).start()

while True:
    time.sleep(1)