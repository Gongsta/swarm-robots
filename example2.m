function varargout = example2(varargin)
% EXAMPLE2 MATLAB code for example2.fig
%      EXAMPLE2, by itself, creates a new EXAMPLE2 or raises the existing
%      singleton*.
%
%      H = EXAMPLE2 returns the handle to a new EXAMPLE2 or the handle to
%      the existing singleton*.
%
%      EXAMPLE2('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in EXAMPLE2.M with the given input arguments.
%
%      EXAMPLE2('Property','Value',...) creates a new EXAMPLE2 or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before example2_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to example2_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help example2

% Last Modified by GUIDE v2.5 06-Feb-2019 05:16:20

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @example2_OpeningFcn, ...
                   'gui_OutputFcn',  @example2_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before example2 is made visible.
function example2_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to example2 (see VARARGIN)

% Choose default command line output for example2
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes example2 wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = example2_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
clear all;
global a;
a = arduino('/dev/tty.usbserial-1430','Nano');

% --- Executes on button press in toggle_on.
function toggle_on_Callback(hObject, eventdata, handles)
% hObject    handle to toggle_on (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of toggle_on
global a;
writeDigitalPin(a,'D8',1);

% --- Executes on button press in toggle_off.
function toggle_off_Callback(hObject, eventdata, handles)
% hObject    handle to toggle_off (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of toggle_off
global a;
writeDigitalPin(a,'D8',0);
