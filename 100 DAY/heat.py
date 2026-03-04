import os
import random
import datetime

# Month select
start_date = datetime.date(2026, 3, 1)
end_date = datetime.date(2026, 3, 30)

current_date = start_date

while current_date <= end_date:
    gap = random.randint(2, 4)
    current_date += datetime.timedelta(days=gap)

    if current_date > end_date:
        break

    # Random time
    time_str = f"{random.randint(10,23)}:{random.randint(0,59)}:00"
    date_str = f"{current_date}T{time_str}"

    # 🔥 IMPORTANT: file change karna
    with open("activity.txt", "a") as f:
        f.write(f"Commit on {date_str}\n")

    # Git commands with date
    os.system("git add .")
    os.system(f'git commit --date="{date_str}" -m "auto commit {date_str}"')
    os.system("git push")

print("Done 🚀")