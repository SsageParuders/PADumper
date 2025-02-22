package com.dumper.android.process

import kotlinx.parcelize.Parcelize
import android.os.Parcelable

@Parcelize
data class ProcessData(val processName: String, val appName: String): Parcelable