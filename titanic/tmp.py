import numpy as np
import pandas as pd
from ydata_profiling import ProfileReport

data = pd.read_csv('C:/Users/MSI/Desktop/ML/titanic/train.csv')

report = ProfileReport(data, title='Profiling report')


