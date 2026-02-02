<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\LocationController;

Route::post('/location', [LocationController::class, 'store']);
Route::get('/location', [LocationController::class, 'latest']);