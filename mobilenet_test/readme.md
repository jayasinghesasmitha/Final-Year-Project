mobilenet_test/
│
├── venv/
│
├── images/
│   └── cat.jpg
│
├── classify.py
│
└── requirements.txt

Run:

python -m venv venv

You'll now have:

mobilenet_test/
└── venv/

Activate it:

venv\Scripts\activate

Install TensorFlow:

pip install tensorflow

Then install Pillow:

pip install pillow

Pillow is used to load and manipulate the image.

You can verify TensorFlow:

python -c "import tensorflow as tf; print(tf.__version__)"

You should see a TensorFlow version number.

