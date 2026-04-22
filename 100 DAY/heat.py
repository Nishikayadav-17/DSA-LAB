import subprocess
import random
import datetime

def run(cmd):
    print("👉", cmd)
    subprocess.run(cmd, shell=True)

start = datetime.date(2026, 3, 1)
end = datetime.date(2026, 3, 30)

date = start

while date <= end:

    # 70% chance commit
    if random.random() < 0.7:

        time = f"{random.randint(10,22)}:{random.randint(0,59)}:00"
        full_date = f"{date}T{time}"

        # file update (IMPORTANT)
        with open("activity.txt", "a") as f:
            f.write(f"{full_date}\n")

        run("git add .")
        run(f'git commit --date="{full_date}" -m "commit {full_date}"')
        run("git push")

    date += datetime.timedelta(days=1)

print("DONE ✅")