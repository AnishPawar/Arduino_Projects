import matplotlib.pyplot as plt
import math
import numpy as np
import cv2

theta = [i*np.pi/180 for i in range(0,181,5)]

r = [
4,
34,
29,
35,
28,
33,
15,
19,
15,
27,
19,
18,
18,
18,
18,
17,
17,
17,
17,
17,
17,
17,
17,
17,
18,
17,
18,
18,
20,
20,
20,
12,
17,
17,
9,
9,
9,
]

plt.polar(theta,r)
plt.show()
