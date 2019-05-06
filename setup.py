#!/usr/bin/env python
# -*- coding: utf-8 -*-

from __future__ import absolute_import, division, print_function

from setuptools import find_packages, setup
from setuptools.dist import Distribution

__version__ = '0.0.1'
REQUIRED_PACKAGES = [
    'tensorflow >= 1.12.0',
]
project_name = 'wobble-interp'


class BinaryDistribution(Distribution):
    """This class is needed in order to create OS specific wheels."""

    def has_ext_modules(self):
        return True


setup(
    name=project_name,
    version=__version__,
    description=('Iterpolation for wobble'),
    author='Dan Foreman-Mackey',
    author_email='foreman.mackey@gmail.com',
    # Contained modules and scripts.
    packages=find_packages(),
    install_requires=REQUIRED_PACKAGES,
    # Add in any packaged data.
    include_package_data=True,
    zip_safe=False,
    distclass=BinaryDistribution,
    # PyPI package information.
    classifiers=[
        # 'Development Status :: 4 - Beta',
        # 'Intended Audience :: Developers',
        # 'Intended Audience :: Education',
        # 'Intended Audience :: Science/Research',
        # 'License :: OSI Approved :: Apache Software License',
        # 'Programming Language :: Python :: 2.7',
        # 'Programming Language :: Python :: 3.4',
        # 'Programming Language :: Python :: 3.5',
        # 'Programming Language :: Python :: 3.6',
        # 'Topic :: Scientific/Engineering :: Mathematics',
        # 'Topic :: Software Development :: Libraries :: Python Modules',
        # 'Topic :: Software Development :: Libraries',
    ],
    license='MIT',
)
