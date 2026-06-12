from setuptools import setup, Extension

module = Extension(
    'pyperf._metrics',
    sources=['src/metrics.c'],
)

setup(
    name='pyperf',
    version='1.0.2',
    description='Lightweight system performance metrics',
    packages=['pyperf'],
    ext_modules=[module],
)