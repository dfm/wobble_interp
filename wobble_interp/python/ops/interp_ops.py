# -*- coding: utf-8 -*-

from __future__ import absolute_import

__all__ = ["interp"]

from tensorflow.python.framework import load_library
from tensorflow.python.platform import resource_loader

interp_ops = load_library.load_op_library(
    resource_loader.get_path_to_datafile('_interp_ops.so'))
interp = interp_ops.interp
