import setuptools 
from setuptools import Extension, setup 
setup( 
    name="batchtool", 
    version="0.1.0", 
    description="Batch processing utilities", 
    ext_modules=[ 
        Extension( 
            "batchtool.core", 
            sources=["batchtool/src/core.c"], 
        ) 
    ], 
    packages=["batchtool"], 
    zip_safe=False, 
) 
