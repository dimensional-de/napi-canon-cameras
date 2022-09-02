# Modules

<dl>
<dt><a href="#module_CameraApi">CameraApi</a></dt>
<dd></dd>
</dl>

# Classes

<dl>
<dt><a href="#Aperture">Aperture</a></dt>
<dd></dd>
<dt><a href="#ApiError">ApiError</a> ⇐ <code><a href="#ApiIdentifier">ApiIdentifier</a></code></dt>
<dd></dd>
<dt><a href="#ApiIdentifier">ApiIdentifier</a></dt>
<dd></dd>
<dt><a href="#Camera">Camera</a></dt>
<dd></dd>
<dt><a href="#CameraBrowser">CameraBrowser</a></dt>
<dd></dd>
<dt><a href="#CameraFile">CameraFile</a></dt>
<dd></dd>
<dt><a href="#CameraProperty">CameraProperty</a></dt>
<dd></dd>
<dt><a href="#Directory">Directory</a></dt>
<dd></dd>
<dt><a href="#ExposureCompensation">ExposureCompensation</a></dt>
<dd></dd>
<dt><a href="#FileFormat">FileFormat</a></dt>
<dd></dd>
<dt><a href="#Flag">Flag</a></dt>
<dd></dd>
<dt><a href="#ImageQuality">ImageQuality</a></dt>
<dd></dd>
<dt><a href="#ISOSensitivity">ISOSensitivity</a></dt>
<dd></dd>
<dt><a href="#LiveViewImage">LiveViewImage</a></dt>
<dd></dd>
<dt><a href="#ObjectEvent">ObjectEvent</a> ⇐ <code><a href="#ApiIdentifier">ApiIdentifier</a></code></dt>
<dd></dd>
<dt><a href="#Option">Option</a></dt>
<dd></dd>
<dt><a href="#Flag">Flag</a></dt>
<dd></dd>
<dt><a href="#ShutterSpeed">ShutterSpeed</a></dt>
<dd></dd>
<dt><a href="#StateEvent">StateEvent</a> ⇐ <code><a href="#ApiIdentifier">ApiIdentifier</a></code></dt>
<dd></dd>
<dt><a href="#TimeZone">TimeZone</a></dt>
<dd></dd>
<dt><a href="#Volume">Volume</a></dt>
<dd></dd>
</dl>

# Constants

<dl>
<dt><a href="#watchCameras">watchCameras</a> ⇒ <code>function</code></dt>
<dd><p>Watch for camera events</p>
</dd>
<dt><a href="#cameraBrowser">cameraBrowser</a> : <code><a href="#CameraBrowser">CameraBrowser</a></code></dt>
<dd><p>Global CameraBrowser instance</p>
</dd>
</dl>

# Typedefs

<dl>
<dt><a href="#EventCallback">EventCallback</a> : <code>function</code></dt>
<dd></dd>
<dt><a href="#CameraPropertyValue">CameraPropertyValue</a> : <code>string</code> | <code>number</code> | <code>Array.&lt;number&gt;</code> | <code><a href="#PropertyValue">PropertyValue</a></code></dt>
<dd></dd>
</dl>

# Interfaces

<dl>
<dt><a href="#CameraDeviceEvent">CameraDeviceEvent</a></dt>
<dd></dd>
<dt><a href="#PropertyChangeEvent">PropertyChangeEvent</a> ⇐ <code><a href="#CameraDeviceEvent">CameraDeviceEvent</a></code></dt>
<dd></dd>
<dt><a href="#FileChangeEvent">FileChangeEvent</a> ⇐ <code><a href="#CameraDeviceEvent">CameraDeviceEvent</a></code></dt>
<dd></dd>
<dt><a href="#DirectoryChangeEvent">DirectoryChangeEvent</a> ⇐ <code><a href="#CameraDeviceEvent">CameraDeviceEvent</a></code></dt>
<dd></dd>
<dt><a href="#VolumeChangeEvent">VolumeChangeEvent</a> ⇐ <code><a href="#CameraDeviceEvent">CameraDeviceEvent</a></code></dt>
<dd></dd>
<dt><a href="#ObjectChangeEvent">ObjectChangeEvent</a> ⇐ <code><a href="#CameraDeviceEvent">CameraDeviceEvent</a></code></dt>
<dd></dd>
<dt><a href="#StateChangeEvent">StateChangeEvent</a> ⇐ <code><a href="#CameraDeviceEvent">CameraDeviceEvent</a></code></dt>
<dd></dd>
<dt><a href="#PropertyValue">PropertyValue</a></dt>
<dd></dd>
<dt><a href="#MatchablePropertyValue">MatchablePropertyValue</a></dt>
<dd></dd>
<dt><a href="#PropertyDateTime">PropertyDateTime</a> ⇐ <code><a href="#PropertyValue">PropertyValue</a></code></dt>
<dd></dd>
<dt><a href="#PropertyStyleDescription">PropertyStyleDescription</a> ⇐ <code><a href="#PropertyValue">PropertyValue</a></code></dt>
<dd></dd>
<dt><a href="#DirectoryEntry">DirectoryEntry</a></dt>
<dd></dd>
<dt><a href="#ImageQualityProperties">ImageQualityProperties</a></dt>
<dd></dd>
</dl>

<a name="module_CameraApi"></a>

# CameraApi
<a name="CameraDeviceEvent"></a>

# CameraDeviceEvent
**Kind**: global interface  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr>  </tbody>
</table>

<a name="PropertyChangeEvent"></a>

# PropertyChangeEvent ⇐ [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)
**Kind**: global interface  
**Extends**: [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>property</td><td><code><a href="#CameraProperty">CameraProperty</a></code></td>
    </tr>  </tbody>
</table>

<a name="FileChangeEvent"></a>

# FileChangeEvent ⇐ [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)
**Kind**: global interface  
**Extends**: [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>file</td><td><code><a href="#CameraFile">CameraFile</a></code></td>
    </tr>  </tbody>
</table>

<a name="DirectoryChangeEvent"></a>

# DirectoryChangeEvent ⇐ [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)
**Kind**: global interface  
**Extends**: [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>file</td><td><code><a href="#CameraFile">CameraFile</a></code></td>
    </tr>  </tbody>
</table>

<a name="VolumeChangeEvent"></a>

# VolumeChangeEvent ⇐ [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)
**Kind**: global interface  
**Extends**: [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>file</td><td><code><a href="#CameraFile">CameraFile</a></code></td>
    </tr>  </tbody>
</table>

<a name="ObjectChangeEvent"></a>

# ObjectChangeEvent ⇐ [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)
**Kind**: global interface  
**Extends**: [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>objectEvent</td><td><code><a href="#ObjectEvent">ObjectEvent</a></code></td>
    </tr>  </tbody>
</table>

<a name="StateChangeEvent"></a>

# StateChangeEvent ⇐ [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)
**Kind**: global interface  
**Extends**: [<code>CameraDeviceEvent</code>](#CameraDeviceEvent)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>stateEvent</td><td><code><a href="#StateEvent">StateEvent</a></code></td>
    </tr>  </tbody>
</table>

<a name="PropertyValue"></a>

# PropertyValue
**Kind**: global interface  
<a name="MatchablePropertyValue"></a>

# MatchablePropertyValue
**Kind**: global interface  

* [MatchablePropertyValue](#MatchablePropertyValue)
    * [.findNearest(needle)](#MatchablePropertyValue+findNearest)
    * [.findNearestFilter](#MatchablePropertyValue+findNearestFilter) ⇒ <code>boolean</code>

<a name="MatchablePropertyValue+findNearest"></a>

## matchablePropertyValue.findNearest(needle)
**Kind**: instance method of [<code>MatchablePropertyValue</code>](#MatchablePropertyValue)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>needle</td><td><code>string</code> | <code>number</code></td>
    </tr><tr>
    <td></td><td><code>MatchablePropertyValue~findNearestFilter</code></td>
    </tr>  </tbody>
</table>

<a name="MatchablePropertyValue+findNearestFilter"></a>

## matchablePropertyValue.findNearestFilter ⇒ <code>boolean</code>
**Kind**: instance typedef of [<code>MatchablePropertyValue</code>](#MatchablePropertyValue)  
**Returns**: <code>boolean</code> - isAllowed  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value</td><td><code><a href="#MatchablePropertyValue">MatchablePropertyValue</a></code></td>
    </tr>  </tbody>
</table>

<a name="PropertyDateTime"></a>

# PropertyDateTime ⇐ [<code>PropertyValue</code>](#PropertyValue)
**Kind**: global interface  
**Extends**: [<code>PropertyValue</code>](#PropertyValue)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>year</td><td><code>number</code></td>
    </tr><tr>
    <td>month</td><td><code>number</code></td>
    </tr><tr>
    <td>day</td><td><code>number</code></td>
    </tr><tr>
    <td>hour</td><td><code>number</code></td>
    </tr><tr>
    <td>minute</td><td><code>number</code></td>
    </tr><tr>
    <td>seconds</td><td><code>number</code></td>
    </tr><tr>
    <td>milliseconds</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="PropertyStyleDescription"></a>

# PropertyStyleDescription ⇐ [<code>PropertyValue</code>](#PropertyValue)
**Kind**: global interface  
**Extends**: [<code>PropertyValue</code>](#PropertyValue)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>contrast</td><td><code>number</code></td>
    </tr><tr>
    <td>sharpness</td><td><code>number</code></td>
    </tr><tr>
    <td>saturation</td><td><code>number</code></td>
    </tr><tr>
    <td>colorTone</td><td><code>number</code></td>
    </tr><tr>
    <td>filterEffect</td><td><code>number</code></td>
    </tr><tr>
    <td>toningEffect</td><td><code>number</code></td>
    </tr><tr>
    <td>sharpFineness</td><td><code>number</code></td>
    </tr><tr>
    <td>sharpThreshold</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="DirectoryEntry"></a>

# DirectoryEntry
**Kind**: global interface  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>name</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="ImageQualityProperties"></a>

# ImageQualityProperties
**Kind**: global interface  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>format</td><td><code>number</code></td>
    </tr><tr>
    <td>size</td><td><code>number</code></td>
    </tr><tr>
    <td>quality</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="Aperture"></a>

# Aperture
**Kind**: global class  
**Implements**: [<code>PropertyValue</code>](#PropertyValue)  

* [Aperture](#Aperture)
    * [new Aperture(value_)](#new_Aperture_new)
    * _instance_
        * [.label](#Aperture+label) : <code>string</code>
        * [.value](#Aperture+value) : <code>number</code>
        * [.aperture](#Aperture+aperture) : <code>number</code>
        * [.stop](#Aperture+stop) : <code>number</code>
        * [.toJSON()](#Aperture+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.ID](#Aperture.ID) : <code>enum</code>
        * [.OneHalfValues](#Aperture.OneHalfValues) : <code>enum</code>
        * [.OneThirdValues](#Aperture.OneThirdValues) : <code>enum</code>
        * [.forLabel(label)](#Aperture.forLabel) ⇒ [<code>Aperture</code>](#Aperture) \| <code>null</code>

<a name="new_Aperture_new"></a>

## new Aperture(value_)
Aperture property value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value_</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="Aperture+label"></a>

## aperture.label : <code>string</code>
**Kind**: instance property of [<code>Aperture</code>](#Aperture)  
**Read only**: true  
<a name="Aperture+value"></a>

## aperture.value : <code>number</code>
**Kind**: instance property of [<code>Aperture</code>](#Aperture)  
**Read only**: true  
<a name="Aperture+aperture"></a>

## aperture.aperture : <code>number</code>
**Kind**: instance property of [<code>Aperture</code>](#Aperture)  
**Read only**: true  
<a name="Aperture+stop"></a>

## aperture.stop : <code>number</code>
**Kind**: instance property of [<code>Aperture</code>](#Aperture)  
**Read only**: true  
<a name="Aperture+toJSON"></a>

## aperture.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>Aperture</code>](#Aperture)  
<a name="Aperture.ID"></a>

## Aperture.ID : <code>enum</code>
**Kind**: static enum of [<code>Aperture</code>](#Aperture)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Auto</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>NotValid</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr>  </tbody>
</table>

<a name="Aperture.OneHalfValues"></a>

## Aperture.OneHalfValues : <code>enum</code>
**Kind**: static enum of [<code>Aperture</code>](#Aperture)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>8</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>11</td><td><code>number</code></td><td><code>1.1</code></td>
    </tr><tr>
    <td>12</td><td><code>number</code></td><td><code>1.2</code></td>
    </tr><tr>
    <td>16</td><td><code>number</code></td><td><code>1.4</code></td>
    </tr><tr>
    <td>19</td><td><code>number</code></td><td><code>1.6</code></td>
    </tr><tr>
    <td>20</td><td><code>number</code></td><td><code>1.8</code></td>
    </tr><tr>
    <td>24</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>27</td><td><code>number</code></td><td><code>2.2</code></td>
    </tr><tr>
    <td>28</td><td><code>number</code></td><td><code>2.5</code></td>
    </tr><tr>
    <td>32</td><td><code>number</code></td><td><code>2.8</code></td>
    </tr><tr>
    <td>35</td><td><code>number</code></td><td><code>3.2</code></td>
    </tr><tr>
    <td>36</td><td><code>number</code></td><td><code>3.5</code></td>
    </tr><tr>
    <td>40</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>43</td><td><code>number</code></td><td><code>4.5</code></td>
    </tr><tr>
    <td>44</td><td><code>number</code></td><td><code>4.5</code></td>
    </tr><tr>
    <td>45</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>48</td><td><code>number</code></td><td><code>5.6</code></td>
    </tr><tr>
    <td>51</td><td><code>number</code></td><td><code>6.3</code></td>
    </tr><tr>
    <td>52</td><td><code>number</code></td><td><code>6.7</code></td>
    </tr><tr>
    <td>53</td><td><code>number</code></td><td><code>7.1</code></td>
    </tr><tr>
    <td>56</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>59</td><td><code>number</code></td><td><code>9</code></td>
    </tr><tr>
    <td>60</td><td><code>number</code></td><td><code>9.5</code></td>
    </tr><tr>
    <td>61</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>64</td><td><code>number</code></td><td><code>11</code></td>
    </tr><tr>
    <td>68</td><td><code>number</code></td><td><code>13</code></td>
    </tr><tr>
    <td>69</td><td><code>number</code></td><td><code>14</code></td>
    </tr><tr>
    <td>72</td><td><code>number</code></td><td><code>16</code></td>
    </tr><tr>
    <td>75</td><td><code>number</code></td><td><code>18</code></td>
    </tr><tr>
    <td>76</td><td><code>number</code></td><td><code>19</code></td>
    </tr><tr>
    <td>77</td><td><code>number</code></td><td><code>20</code></td>
    </tr><tr>
    <td>80</td><td><code>number</code></td><td><code>22</code></td>
    </tr><tr>
    <td>83</td><td><code>number</code></td><td><code>25</code></td>
    </tr><tr>
    <td>84</td><td><code>number</code></td><td><code>27</code></td>
    </tr><tr>
    <td>85</td><td><code>number</code></td><td><code>29</code></td>
    </tr><tr>
    <td>88</td><td><code>number</code></td><td><code>32</code></td>
    </tr><tr>
    <td>91</td><td><code>number</code></td><td><code>36</code></td>
    </tr><tr>
    <td>92</td><td><code>number</code></td><td><code>38</code></td>
    </tr><tr>
    <td>93</td><td><code>number</code></td><td><code>40</code></td>
    </tr><tr>
    <td>96</td><td><code>number</code></td><td><code>45</code></td>
    </tr><tr>
    <td>99</td><td><code>number</code></td><td><code>51</code></td>
    </tr><tr>
    <td>100</td><td><code>number</code></td><td><code>54</code></td>
    </tr><tr>
    <td>101</td><td><code>number</code></td><td><code>57</code></td>
    </tr><tr>
    <td>104</td><td><code>number</code></td><td><code>64</code></td>
    </tr><tr>
    <td>107</td><td><code>number</code></td><td><code>72</code></td>
    </tr><tr>
    <td>108</td><td><code>number</code></td><td><code>76</code></td>
    </tr><tr>
    <td>109</td><td><code>number</code></td><td><code>80</code></td>
    </tr><tr>
    <td>112</td><td><code>number</code></td><td><code>91</code></td>
    </tr><tr>
    <td>133</td><td><code>number</code></td><td><code>3.4</code></td>
    </tr>  </tbody>
</table>

<a name="Aperture.OneThirdValues"></a>

## Aperture.OneThirdValues : <code>enum</code>
**Kind**: static enum of [<code>Aperture</code>](#Aperture)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>13</td><td><code>number</code></td><td><code>1.2</code></td>
    </tr><tr>
    <td>21</td><td><code>number</code></td><td><code>1.8</code></td>
    </tr><tr>
    <td>29</td><td><code>number</code></td><td><code>2.5</code></td>
    </tr><tr>
    <td>37</td><td><code>number</code></td><td><code>3.5</code></td>
    </tr><tr>
    <td>67</td><td><code>number</code></td><td><code>13</code></td>
    </tr>  </tbody>
</table>

<a name="Aperture.forLabel"></a>

## Aperture.forLabel(label) ⇒ [<code>Aperture</code>](#Aperture) \| <code>null</code>
Create instance for label.

**Kind**: static method of [<code>Aperture</code>](#Aperture)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>label</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="ApiError"></a>

# ApiError ⇐ [<code>ApiIdentifier</code>](#ApiIdentifier)
**Kind**: global class  
**Extends**: [<code>ApiIdentifier</code>](#ApiIdentifier)  

* [ApiError](#ApiError) ⇐ [<code>ApiIdentifier</code>](#ApiIdentifier)
    * [new ApiError()](#new_ApiError_new)
    * _instance_
        * [.label](#ApiIdentifier+label) : <code>string</code>
        * [.identifier](#ApiIdentifier+identifier) : <code>number</code>
        * [.equalTo(other)](#ApiError+equalTo) ⇒ <code>boolean</code>
        * [.Symbol_toPrimitive(hint)](#ApiIdentifier+Symbol_toPrimitive) ⇒ <code>string</code> \| <code>number</code> \| <code>null</code>
        * [.toJSON()](#ApiIdentifier+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.Code](#ApiError.Code) : <code>enum</code>

<a name="new_ApiError_new"></a>

## new ApiError()
An internal class that will be added to Exceptions as "EDS_ERROR" property.

**Example**  

```typescripttry {} catch (e) {  if ("EDS_ERROR" in e && e.EDS_ERROR.equalTo(ApiError.Code.DEVICE_BUSY)) {  }}```

<a name="ApiIdentifier+label"></a>

## apiError.label : <code>string</code>
**Kind**: instance property of [<code>ApiError</code>](#ApiError)  
**Read only**: true  
<a name="ApiIdentifier+identifier"></a>

## apiError.identifier : <code>number</code>
**Kind**: instance property of [<code>ApiError</code>](#ApiError)  
**Read only**: true  
<a name="ApiError+equalTo"></a>

## apiError.equalTo(other) ⇒ <code>boolean</code>
**Kind**: instance method of [<code>ApiError</code>](#ApiError)  
**Overrides**: [<code>equalTo</code>](#ApiIdentifier+equalTo)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Description</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>other</td><td><code>number</code> | <code><a href="#ApiError">ApiError</a></code></td><td><p>The other value</p>
</td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+Symbol_toPrimitive"></a>

## apiError.Symbol\_toPrimitive(hint) ⇒ <code>string</code> \| <code>number</code> \| <code>null</code>
Allows type cast to number and string.The string will be a hexadecimal code representation of the number

**Kind**: instance method of [<code>ApiError</code>](#ApiError)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>hint</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+toJSON"></a>

## apiError.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>ApiError</code>](#ApiError)  
<a name="ApiError.Code"></a>

## ApiError.Code : <code>enum</code>
**Kind**: static enum of [<code>ApiError</code>](#ApiError)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>CANNOT_MAKE_OBJECT</td><td><code>number</code></td><td><code>41220</code></td>
    </tr><tr>
    <td>CAPTURE_ALREADY_TERMINATED</td><td><code>number</code></td><td><code>8216</code></td>
    </tr><tr>
    <td>COMM_BUFFER_FULL</td><td><code>number</code></td><td><code>195</code></td>
    </tr><tr>
    <td>COMM_DEVICE_INCOMPATIBLE</td><td><code>number</code></td><td><code>194</code></td>
    </tr><tr>
    <td>COMM_DISCONNECTED</td><td><code>number</code></td><td><code>193</code></td>
    </tr><tr>
    <td>COMM_PORT_IS_IN_USE</td><td><code>number</code></td><td><code>192</code></td>
    </tr><tr>
    <td>COMM_USB_BUS_ERR</td><td><code>number</code></td><td><code>196</code></td>
    </tr><tr>
    <td>DEVICEPROP_NOT_SUPPORTED</td><td><code>number</code></td><td><code>8202</code></td>
    </tr><tr>
    <td>DEVICE_BUSY</td><td><code>number</code></td><td><code>129</code></td>
    </tr><tr>
    <td>DEVICE_CF_GATE_CHANGED</td><td><code>number</code></td><td><code>137</code></td>
    </tr><tr>
    <td>DEVICE_DIAL_CHANGED</td><td><code>number</code></td><td><code>138</code></td>
    </tr><tr>
    <td>DEVICE_DISK_ERROR</td><td><code>number</code></td><td><code>136</code></td>
    </tr><tr>
    <td>DEVICE_EMERGENCY</td><td><code>number</code></td><td><code>131</code></td>
    </tr><tr>
    <td>DEVICE_INTERNAL_ERROR</td><td><code>number</code></td><td><code>133</code></td>
    </tr><tr>
    <td>DEVICE_INVALID</td><td><code>number</code></td><td><code>130</code></td>
    </tr><tr>
    <td>DEVICE_INVALID_PARAMETER</td><td><code>number</code></td><td><code>134</code></td>
    </tr><tr>
    <td>DEVICE_MEMORY_FULL</td><td><code>number</code></td><td><code>132</code></td>
    </tr><tr>
    <td>DEVICE_NOT_FOUND</td><td><code>number</code></td><td><code>128</code></td>
    </tr><tr>
    <td>DEVICE_NOT_INSTALLED</td><td><code>number</code></td><td><code>139</code></td>
    </tr><tr>
    <td>DEVICE_NOT_LAUNCHED</td><td><code>number</code></td><td><code>228</code></td>
    </tr><tr>
    <td>DEVICE_NOT_RELEASED</td><td><code>number</code></td><td><code>141</code></td>
    </tr><tr>
    <td>DEVICE_NO_DISK</td><td><code>number</code></td><td><code>135</code></td>
    </tr><tr>
    <td>DEVICE_STAY_AWAKE</td><td><code>number</code></td><td><code>140</code></td>
    </tr><tr>
    <td>DIR_ENTRY_EXISTS</td><td><code>number</code></td><td><code>67</code></td>
    </tr><tr>
    <td>DIR_ENTRY_NOT_FOUND</td><td><code>number</code></td><td><code>66</code></td>
    </tr><tr>
    <td>DIR_IO_ERROR</td><td><code>number</code></td><td><code>65</code></td>
    </tr><tr>
    <td>DIR_NOT_EMPTY</td><td><code>number</code></td><td><code>68</code></td>
    </tr><tr>
    <td>DIR_NOT_FOUND</td><td><code>number</code></td><td><code>64</code></td>
    </tr><tr>
    <td>ENUM_NA</td><td><code>number</code></td><td><code>240</code></td>
    </tr><tr>
    <td>FILE_ALREADY_EXISTS</td><td><code>number</code></td><td><code>43</code></td>
    </tr><tr>
    <td>FILE_CLOSE_ERROR</td><td><code>number</code></td><td><code>36</code></td>
    </tr><tr>
    <td>FILE_DATA_CORRUPT</td><td><code>number</code></td><td><code>45</code></td>
    </tr><tr>
    <td>FILE_DISK_FULL_ERROR</td><td><code>number</code></td><td><code>42</code></td>
    </tr><tr>
    <td>FILE_FORMAT_UNRECOGNIZED</td><td><code>number</code></td><td><code>44</code></td>
    </tr><tr>
    <td>FILE_IO_ERROR</td><td><code>number</code></td><td><code>32</code></td>
    </tr><tr>
    <td>FILE_NAMING_NA</td><td><code>number</code></td><td><code>46</code></td>
    </tr><tr>
    <td>FILE_NOT_FOUND</td><td><code>number</code></td><td><code>34</code></td>
    </tr><tr>
    <td>FILE_OPEN_ERROR</td><td><code>number</code></td><td><code>35</code></td>
    </tr><tr>
    <td>FILE_PERMISSION_ERROR</td><td><code>number</code></td><td><code>41</code></td>
    </tr><tr>
    <td>FILE_READ_ERROR</td><td><code>number</code></td><td><code>39</code></td>
    </tr><tr>
    <td>FILE_SEEK_ERROR</td><td><code>number</code></td><td><code>37</code></td>
    </tr><tr>
    <td>FILE_TELL_ERROR</td><td><code>number</code></td><td><code>38</code></td>
    </tr><tr>
    <td>FILE_TOO_MANY_OPEN</td><td><code>number</code></td><td><code>33</code></td>
    </tr><tr>
    <td>FILE_WRITE_ERROR</td><td><code>number</code></td><td><code>40</code></td>
    </tr><tr>
    <td>HANDLE_NOT_FOUND</td><td><code>number</code></td><td><code>242</code></td>
    </tr><tr>
    <td>INCOMPATIBLE_VERSION</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>INCOMPLETE_TRANSFER</td><td><code>number</code></td><td><code>8199</code></td>
    </tr><tr>
    <td>INTERNAL_ERROR</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>INVALID_CODE_FORMAT</td><td><code>number</code></td><td><code>8214</code></td>
    </tr><tr>
    <td>INVALID_DEVICEPROP_FORMAT</td><td><code>number</code></td><td><code>8219</code></td>
    </tr><tr>
    <td>INVALID_DEVICEPROP_VALUE</td><td><code>number</code></td><td><code>8220</code></td>
    </tr><tr>
    <td>INVALID_FN_CALL</td><td><code>number</code></td><td><code>241</code></td>
    </tr><tr>
    <td>INVALID_FN_POINTER</td><td><code>number</code></td><td><code>101</code></td>
    </tr><tr>
    <td>INVALID_HANDLE</td><td><code>number</code></td><td><code>97</code></td>
    </tr><tr>
    <td>INVALID_ID</td><td><code>number</code></td><td><code>243</code></td>
    </tr><tr>
    <td>INVALID_INDEX</td><td><code>number</code></td><td><code>99</code></td>
    </tr><tr>
    <td>INVALID_LENGTH</td><td><code>number</code></td><td><code>100</code></td>
    </tr><tr>
    <td>INVALID_OBJECTFORMATCODE</td><td><code>number</code></td><td><code>8203</code></td>
    </tr><tr>
    <td>INVALID_PARAMETER</td><td><code>number</code></td><td><code>96</code></td>
    </tr><tr>
    <td>INVALID_PARENTOBJECT</td><td><code>number</code></td><td><code>8218</code></td>
    </tr><tr>
    <td>INVALID_POINTER</td><td><code>number</code></td><td><code>98</code></td>
    </tr><tr>
    <td>INVALID_SORT_FN</td><td><code>number</code></td><td><code>102</code></td>
    </tr><tr>
    <td>INVALID_STRAGEID</td><td><code>number</code></td><td><code>8200</code></td>
    </tr><tr>
    <td>INVALID_TRANSACTIONID</td><td><code>number</code></td><td><code>8196</code></td>
    </tr><tr>
    <td>LENS_COVER_CLOSE</td><td><code>number</code></td><td><code>40966</code></td>
    </tr><tr>
    <td>LOW_BATTERY</td><td><code>number</code></td><td><code>41217</code></td>
    </tr><tr>
    <td>MEMORYSTATUS_NOTREADY</td><td><code>number</code></td><td><code>41222</code></td>
    </tr><tr>
    <td>MEM_ALLOC_FAILED</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>MEM_FREE_FAILED</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>MISSING_SUBCOMPONENT</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>NOT_CAMERA_SUPPORT_SDK_VERSION</td><td><code>number</code></td><td><code>8225</code></td>
    </tr><tr>
    <td>NOT_SUPPORTED</td><td><code>number</code></td><td><code>7</code></td>
    </tr><tr>
    <td>NO_VALID_OBJECTINFO</td><td><code>number</code></td><td><code>8213</code></td>
    </tr><tr>
    <td>OBJECT_NOTREADY</td><td><code>number</code></td><td><code>41218</code></td>
    </tr><tr>
    <td>OPERATION_CANCELLED</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>OPERATION_REFUSED</td><td><code>number</code></td><td><code>40965</code></td>
    </tr><tr>
    <td>PARTIAL_DELETION</td><td><code>number</code></td><td><code>8210</code></td>
    </tr><tr>
    <td>PROPERTIES_MISMATCH</td><td><code>number</code></td><td><code>81</code></td>
    </tr><tr>
    <td>PROPERTIES_NOT_LOADED</td><td><code>number</code></td><td><code>83</code></td>
    </tr><tr>
    <td>PROPERTIES_UNAVAILABLE</td><td><code>number</code></td><td><code>80</code></td>
    </tr><tr>
    <td>PROTECTION_VIOLATION</td><td><code>number</code></td><td><code>9</code></td>
    </tr><tr>
    <td>PTP_DEVICE_BUSY</td><td><code>number</code></td><td><code>8217</code></td>
    </tr><tr>
    <td>SELECTION_UNAVAILABLE</td><td><code>number</code></td><td><code>11</code></td>
    </tr><tr>
    <td>SELF_TEST_FAILED</td><td><code>number</code></td><td><code>8209</code></td>
    </tr><tr>
    <td>SESSION_ALREADY_OPEN</td><td><code>number</code></td><td><code>8222</code></td>
    </tr><tr>
    <td>SESSION_NOT_OPEN</td><td><code>number</code></td><td><code>8195</code></td>
    </tr><tr>
    <td>SPECIFICATION_BY_FORMAT_UNSUPPORTED</td><td><code>number</code></td><td><code>8212</code></td>
    </tr><tr>
    <td>SPECIFICATION_OF_DESTINATION_UNSUPPORTED</td><td><code>number</code></td><td><code>8224</code></td>
    </tr><tr>
    <td>STI_DEVICE_CREATE_ERROR</td><td><code>number</code></td><td><code>226</code></td>
    </tr><tr>
    <td>STI_DEVICE_RELEASE_ERROR</td><td><code>number</code></td><td><code>227</code></td>
    </tr><tr>
    <td>STI_INTERNAL_ERROR</td><td><code>number</code></td><td><code>225</code></td>
    </tr><tr>
    <td>STI_UNKNOWN_ERROR</td><td><code>number</code></td><td><code>224</code></td>
    </tr><tr>
    <td>STREAM_ALREADY_OPEN</td><td><code>number</code></td><td><code>162</code></td>
    </tr><tr>
    <td>STREAM_BAD_OPTIONS</td><td><code>number</code></td><td><code>171</code></td>
    </tr><tr>
    <td>STREAM_CLOSE_ERROR</td><td><code>number</code></td><td><code>164</code></td>
    </tr><tr>
    <td>STREAM_COULDNT_BEGIN_THREAD</td><td><code>number</code></td><td><code>170</code></td>
    </tr><tr>
    <td>STREAM_END_OF_STREAM</td><td><code>number</code></td><td><code>172</code></td>
    </tr><tr>
    <td>STREAM_IO_ERROR</td><td><code>number</code></td><td><code>160</code></td>
    </tr><tr>
    <td>STREAM_NOT_OPEN</td><td><code>number</code></td><td><code>161</code></td>
    </tr><tr>
    <td>STREAM_OPEN_ERROR</td><td><code>number</code></td><td><code>163</code></td>
    </tr><tr>
    <td>STREAM_PERMISSION_ERROR</td><td><code>number</code></td><td><code>169</code></td>
    </tr><tr>
    <td>STREAM_READ_ERROR</td><td><code>number</code></td><td><code>167</code></td>
    </tr><tr>
    <td>STREAM_SEEK_ERROR</td><td><code>number</code></td><td><code>165</code></td>
    </tr><tr>
    <td>STREAM_TELL_ERROR</td><td><code>number</code></td><td><code>166</code></td>
    </tr><tr>
    <td>STREAM_WRITE_ERROR</td><td><code>number</code></td><td><code>168</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_AF_NG</td><td><code>number</code></td><td><code>36097</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_CARD_NG</td><td><code>number</code></td><td><code>36103</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_CARD_PROTECT_NG</td><td><code>number</code></td><td><code>36104</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_LV_REL_PROHIBIT_MODE_NG</td><td><code>number</code></td><td><code>36109</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_MIRROR_UP_NG</td><td><code>number</code></td><td><code>36099</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_MOVIE_CROP_NG</td><td><code>number</code></td><td><code>36105</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_NO_CARD_NG</td><td><code>number</code></td><td><code>36102</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_NO_LENS_NG</td><td><code>number</code></td><td><code>36107</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_RESERVED</td><td><code>number</code></td><td><code>36098</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_SENSOR_CLEANING_NG</td><td><code>number</code></td><td><code>36100</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_SILENCE_NG</td><td><code>number</code></td><td><code>36101</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_SPECIAL_MOVIE_MODE_NG</td><td><code>number</code></td><td><code>36108</code></td>
    </tr><tr>
    <td>TAKE_PICTURE_STROBO_CHARGE_NG</td><td><code>number</code></td><td><code>36106</code></td>
    </tr><tr>
    <td>TRANSACTION_CANCELLED</td><td><code>number</code></td><td><code>8223</code></td>
    </tr><tr>
    <td>UNEXPECTED_EXCEPTION</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>UNIMPLEMENTED</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>UNKNOWN_COMMAND</td><td><code>number</code></td><td><code>40961</code></td>
    </tr><tr>
    <td>UNKNOWN_VENDOR_CODE</td><td><code>number</code></td><td><code>8215</code></td>
    </tr><tr>
    <td>USB_DEVICE_LOCK_ERROR</td><td><code>number</code></td><td><code>208</code></td>
    </tr><tr>
    <td>USB_DEVICE_UNLOCK_ERROR</td><td><code>number</code></td><td><code>209</code></td>
    </tr><tr>
    <td>WAIT_TIMEOUT_ERROR</td><td><code>number</code></td><td><code>244</code></td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier"></a>

# ApiIdentifier
**Kind**: global class  
**Access**: protected  

* [ApiIdentifier](#ApiIdentifier)
    * [new ApiIdentifier(identifier_, labels)](#new_ApiIdentifier_new)
    * [.label](#ApiIdentifier+label) : <code>string</code>
    * [.identifier](#ApiIdentifier+identifier) : <code>number</code>
    * [.Symbol_toPrimitive(hint)](#ApiIdentifier+Symbol_toPrimitive) ⇒ <code>string</code> \| <code>number</code> \| <code>null</code>
    * [.equalTo(other)](#ApiIdentifier+equalTo) ⇒ <code>boolean</code>
    * [.toJSON()](#ApiIdentifier+toJSON) ⇒ <code>Object</code>

<a name="new_ApiIdentifier_new"></a>

## new ApiIdentifier(identifier_, labels)
Superclass for identifier wrappers. Provides the identifiers as class constants and string representations.

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>identifier_</td><td><code>number</code></td>
    </tr><tr>
    <td>labels</td><td><code>Object.&lt;number&gt;</code></td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+label"></a>

## apiIdentifier.label : <code>string</code>
**Kind**: instance property of [<code>ApiIdentifier</code>](#ApiIdentifier)  
**Read only**: true  
<a name="ApiIdentifier+identifier"></a>

## apiIdentifier.identifier : <code>number</code>
**Kind**: instance property of [<code>ApiIdentifier</code>](#ApiIdentifier)  
**Read only**: true  
<a name="ApiIdentifier+Symbol_toPrimitive"></a>

## apiIdentifier.Symbol\_toPrimitive(hint) ⇒ <code>string</code> \| <code>number</code> \| <code>null</code>
Allows type cast to number and string.The string will be a hexadecimal code representation of the number

**Kind**: instance method of [<code>ApiIdentifier</code>](#ApiIdentifier)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>hint</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+equalTo"></a>

## apiIdentifier.equalTo(other) ⇒ <code>boolean</code>
**Kind**: instance method of [<code>ApiIdentifier</code>](#ApiIdentifier)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Description</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>other</td><td><code>number</code></td><td><p>Value to compare with</p>
</td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+toJSON"></a>

## apiIdentifier.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>ApiIdentifier</code>](#ApiIdentifier)  
<a name="Camera"></a>

# Camera
**Kind**: global class  

* [Camera](#Camera)
    * [new Camera([indexOrPort])](#new_Camera_new)
    * _instance_
        * [.description](#Camera+description)
        * [.portName](#Camera+portName)
        * [.setEventHandler(listener)](#Camera+setEventHandler)
        * [.connect()](#Camera+connect)
        * [.disconnect()](#Camera+disconnect)
        * [.getProperty(propertyID, specifier)](#Camera+getProperty) ⇒ [<code>CameraProperty</code>](#CameraProperty)
        * [.setProperty(propertyID, value)](#Camera+setProperty)
        * [.setProperties(properties)](#Camera+setProperties)
        * [.sendCommand(command, parameter)](#Camera+sendCommand)
        * [.takePicture()](#Camera+takePicture)
        * [.isLiveViewActive()](#Camera+isLiveViewActive) ⇒ <code>boolean</code>
        * [.startLiveView()](#Camera+startLiveView)
        * [.stopLiveView()](#Camera+stopLiveView)
        * <del>[.downloadLiveViewImage()](#Camera+downloadLiveViewImage) ⇒ <code>string</code></del>
        * [.getLiveViewImage()](#Camera+getLiveViewImage) ⇒ [<code>LiveViewImage</code>](#LiveViewImage)
        * [.getVolumes()](#Camera+getVolumes) ⇒ [<code>Array.&lt;Volume&gt;</code>](#Volume)
    * _static_
        * [.EventName](#Camera.EventName) : <code>enum</code>
        * [.Command](#Camera.Command) : <code>enum</code>
        * [.PressShutterButton](#Camera.PressShutterButton) : <code>enum</code>

<a name="new_Camera_new"></a>

## new Camera([indexOrPort])
Camera device

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>[indexOrPort]</td><td><code>number</code> | <code>string</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Camera+description"></a>

## camera.description
**Kind**: instance property of [<code>Camera</code>](#Camera)  
**Read only**: true  
<a name="Camera+portName"></a>

## camera.portName
**Kind**: instance property of [<code>Camera</code>](#Camera)  
**Read only**: true  
<a name="Camera+setEventHandler"></a>

## camera.setEventHandler(listener)
Set event handler callback

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>listener</td><td><code><a href="#EventCallback">EventCallback</a></code></td>
    </tr>  </tbody>
</table>

<a name="Camera+connect"></a>

## camera.connect()
Connect to device

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera+disconnect"></a>

## camera.disconnect()
Disconnect from device

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera+getProperty"></a>

## camera.getProperty(propertyID, specifier) ⇒ [<code>CameraProperty</code>](#CameraProperty)
Fetch a camera property by ID or label

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>propertyID</td><td><code>number</code> | <code>string</code></td><td></td>
    </tr><tr>
    <td>specifier</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Camera+setProperty"></a>

## camera.setProperty(propertyID, value)
**Kind**: instance method of [<code>Camera</code>](#Camera)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>propertyID</td><td><code>PropertyIdentifier</code></td>
    </tr><tr>
    <td>value</td><td><code><a href="#PropertyValue">PropertyValue</a></code></td>
    </tr>  </tbody>
</table>

<a name="Camera+setProperties"></a>

## camera.setProperties(properties)
**Kind**: instance method of [<code>Camera</code>](#Camera)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>properties</td><td><code>PropertiesData</code></td>
    </tr>  </tbody>
</table>

<a name="Camera+sendCommand"></a>

## camera.sendCommand(command, parameter)
**Kind**: instance method of [<code>Camera</code>](#Camera)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>command</td><td><code>number</code></td><td></td>
    </tr><tr>
    <td>parameter</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Camera+takePicture"></a>

## camera.takePicture()
Trigger picture shot, successful shot will trigger an object event

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera+isLiveViewActive"></a>

## camera.isLiveViewActive() ⇒ <code>boolean</code>
Return true if the LiveView is currently active

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera+startLiveView"></a>

## camera.startLiveView()
Request LiveView start, triggers event on success

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera+stopLiveView"></a>

## camera.stopLiveView()
Request LiveView stop, triggers event on success

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera+downloadLiveViewImage"></a>

## <del>camera.downloadLiveViewImage() ⇒ <code>string</code></del>
***Deprecated***

**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera+getLiveViewImage"></a>

## camera.getLiveViewImage() ⇒ [<code>LiveViewImage</code>](#LiveViewImage)
**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera+getVolumes"></a>

## camera.getVolumes() ⇒ [<code>Array.&lt;Volume&gt;</code>](#Volume)
**Kind**: instance method of [<code>Camera</code>](#Camera)  
<a name="Camera.EventName"></a>

## Camera.EventName : <code>enum</code>
**Kind**: static enum of [<code>Camera</code>](#Camera)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>CameraConnect</td><td><code>string</code></td><td><code>&quot;CameraConnect&quot;</code></td>
    </tr><tr>
    <td>CameraDisconnect</td><td><code>string</code></td><td><code>&quot;CameraDisconnect&quot;</code></td>
    </tr><tr>
    <td>DirectoryCreate</td><td><code>string</code></td><td><code>&quot;DirectoryCreate&quot;</code></td>
    </tr><tr>
    <td>DownloadRequest</td><td><code>string</code></td><td><code>&quot;DownloadRequest&quot;</code></td>
    </tr><tr>
    <td>Error</td><td><code>string</code></td><td><code>&quot;Error&quot;</code></td>
    </tr><tr>
    <td>FileCreate</td><td><code>string</code></td><td><code>&quot;FileCreate&quot;</code></td>
    </tr><tr>
    <td>KeepAlive</td><td><code>string</code></td><td><code>&quot;KeepAlive&quot;</code></td>
    </tr><tr>
    <td>LiveViewStart</td><td><code>string</code></td><td><code>&quot;LiveViewStart&quot;</code></td>
    </tr><tr>
    <td>LiveViewStop</td><td><code>string</code></td><td><code>&quot;LiveViewStop&quot;</code></td>
    </tr><tr>
    <td>ObjectChange</td><td><code>string</code></td><td><code>&quot;ObjectChange&quot;</code></td>
    </tr><tr>
    <td>PropertyChangeOptions</td><td><code>string</code></td><td><code>&quot;PropertyChangeOptions&quot;</code></td>
    </tr><tr>
    <td>PropertyChangeValue</td><td><code>string</code></td><td><code>&quot;PropertyChangeValue&quot;</code></td>
    </tr><tr>
    <td>StateChange</td><td><code>string</code></td><td><code>&quot;StateChange&quot;</code></td>
    </tr><tr>
    <td>VolumeChange</td><td><code>string</code></td><td><code>&quot;VolumeChange&quot;</code></td>
    </tr>  </tbody>
</table>

<a name="Camera.Command"></a>

## Camera.Command : <code>enum</code>
**Kind**: static enum of [<code>Camera</code>](#Camera)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>BulbEnd</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>BulbStart</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>DoClickWBEvf</td><td><code>number</code></td><td><code>260</code></td>
    </tr><tr>
    <td>DoEvfAf</td><td><code>number</code></td><td><code>258</code></td>
    </tr><tr>
    <td>DriveLensEvf</td><td><code>number</code></td><td><code>259</code></td>
    </tr><tr>
    <td>DrivePowerZoom</td><td><code>number</code></td><td><code>269</code></td>
    </tr><tr>
    <td>ExtendShutDownTimer</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>MovieSelectSwOFF</td><td><code>number</code></td><td><code>264</code></td>
    </tr><tr>
    <td>MovieSelectSwON</td><td><code>number</code></td><td><code>263</code></td>
    </tr><tr>
    <td>PressShutterButton</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>RequestRollPitchLevel</td><td><code>number</code></td><td><code>265</code></td>
    </tr><tr>
    <td>RequestSensorCleaning</td><td><code>number</code></td><td><code>274</code></td>
    </tr><tr>
    <td>SetRemoteShootingMode</td><td><code>number</code></td><td><code>271</code></td>
    </tr><tr>
    <td>TakePicture</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Camera.PressShutterButton"></a>

## Camera.PressShutterButton : <code>enum</code>
**Kind**: static enum of [<code>Camera</code>](#Camera)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Completely</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>CompletelyNonAF</td><td><code>number</code></td><td><code>65539</code></td>
    </tr><tr>
    <td>Halfway</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>HalfwayNonAF</td><td><code>number</code></td><td><code>65537</code></td>
    </tr><tr>
    <td>OFF</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser"></a>

# CameraBrowser
**Kind**: global class  
**Emits**: [<code>CameraAdd</code>](#CameraBrowser+event_CameraAdd), [<code>CameraRemove</code>](#CameraBrowser+event_CameraRemove), [<code>Error</code>](#CameraBrowser+event_Error), [<code>ObjectChange</code>](#CameraBrowser+event_ObjectChange), [<code>StateChange</code>](#CameraBrowser+event_StateChange), [<code>PropertyChangeValue</code>](#CameraBrowser+event_PropertyChangeValue), <code>CameraBrowser#event:PropertyChangeAllowed</code>, [<code>DownloadRequest</code>](#CameraBrowser+event_DownloadRequest), [<code>LiveViewStart</code>](#CameraBrowser+event_LiveViewStart), [<code>LiveViewStop</code>](#CameraBrowser+event_LiveViewStop)  

* [CameraBrowser](#CameraBrowser)
    * [new CameraBrowser()](#new_CameraBrowser_new)
    * _instance_
        * [.setEventHandler(listener)](#CameraBrowser+setEventHandler)
        * [.initialize()](#CameraBrowser+initialize)
        * [.terminate()](#CameraBrowser+terminate)
        * [.triggerEvents()](#CameraBrowser+triggerEvents)
        * [.getCamera([at], [exactOnly])](#CameraBrowser+getCamera)
        * [.getCameras()](#CameraBrowser+getCameras) ⇒ [<code>Array.&lt;Camera&gt;</code>](#Camera)
        * [.update()](#CameraBrowser+update)
        * ["CameraAdd"](#CameraBrowser+event_CameraAdd)
        * ["CameraRemove"](#CameraBrowser+event_CameraRemove)
        * ["PropertyChangeValue"](#CameraBrowser+event_PropertyChangeValue)
        * ["PropertyChangeOptions"](#CameraBrowser+event_PropertyChangeOptions)
        * ["DownloadRequest"](#CameraBrowser+event_DownloadRequest)
        * ["ObjectChange"](#CameraBrowser+event_ObjectChange)
        * ["StateChange"](#CameraBrowser+event_StateChange)
        * ["LiveViewStart"](#CameraBrowser+event_LiveViewStart)
        * ["LiveViewStop"](#CameraBrowser+event_LiveViewStop)
        * ["Error"](#CameraBrowser+event_Error)
    * _static_
        * [.EventName](#CameraBrowser.EventName) : <code>enum</code>

<a name="new_CameraBrowser_new"></a>

## new CameraBrowser()
Access to Canon Cameras

**Example**  

```typescriptconst {cameraBrowser, watchCameras} = require('@dimensional/napi-canon-cameras');cameraBrowser.setEventHandler(  (eventName, event) => { console.log(eventName, event); });process.on('SIGINT', () => process.exit());console.log(cameraBrowser.getCameras());watchCameras();```

<a name="CameraBrowser+setEventHandler"></a>

## cameraBrowser.setEventHandler(listener)
Set event handler callback

**Kind**: instance method of [<code>CameraBrowser</code>](#CameraBrowser)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>listener</td><td><code><a href="#EventCallback">EventCallback</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+initialize"></a>

## cameraBrowser.initialize()
Initialize SDK

**Kind**: instance method of [<code>CameraBrowser</code>](#CameraBrowser)  
<a name="CameraBrowser+terminate"></a>

## cameraBrowser.terminate()
Terminate SDK and free all resources

**Kind**: instance method of [<code>CameraBrowser</code>](#CameraBrowser)  
<a name="CameraBrowser+triggerEvents"></a>

## cameraBrowser.triggerEvents()
Trigger SDK events

**Kind**: instance method of [<code>CameraBrowser</code>](#CameraBrowser)  
<a name="CameraBrowser+getCamera"></a>

## cameraBrowser.getCamera([at], [exactOnly])
Get camera at port or index. Returns the first camera in the internal list ifport or position is invalid. USe the exactOnly argument to disable the fallback.

**Kind**: instance method of [<code>CameraBrowser</code>](#CameraBrowser)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Default</th><th>Description</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>[at]</td><td><code>string</code> | <code>number</code></td><td><code>0</code></td><td><p>index or port name</p>
</td>
    </tr><tr>
    <td>[exactOnly]</td><td><code>boolean</code></td><td><code>false</code></td><td></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+getCameras"></a>

## cameraBrowser.getCameras() ⇒ [<code>Array.&lt;Camera&gt;</code>](#Camera)
Get currently connected cameras.

**Kind**: instance method of [<code>CameraBrowser</code>](#CameraBrowser)  
<a name="CameraBrowser+update"></a>

## cameraBrowser.update()
Update internal camera list

**Kind**: instance method of [<code>CameraBrowser</code>](#CameraBrowser)  
<a name="CameraBrowser+event_CameraAdd"></a>

## "CameraAdd"
New camera found

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_CameraRemove"></a>

## "CameraRemove"
Camera removed or not found while enumerating current devices

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_PropertyChangeValue"></a>

## "PropertyChangeValue"
Property value change

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>property</td><td><code><a href="#CameraProperty">CameraProperty</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_PropertyChangeOptions"></a>

## "PropertyChangeOptions"
Property value change

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>property</td><td><code><a href="#CameraProperty">CameraProperty</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_DownloadRequest"></a>

## "DownloadRequest"
New image available for download

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>file</td><td><code><a href="#CameraFile">CameraFile</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_ObjectChange"></a>

## "ObjectChange"
Generic object change event, for debugging

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>objectEvent</td><td><code><a href="#ObjectEvent">ObjectEvent</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_StateChange"></a>

## "StateChange"
Camera state changed

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr><tr>
    <td>stateEvent</td><td><code>StateChange</code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_LiveViewStart"></a>

## "LiveViewStart"
Camera live view started

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_LiveViewStop"></a>

## "LiveViewStop"
Camera live view stopped

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraBrowser+event_Error"></a>

## "Error"
API Error

**Kind**: event emitted by [<code>CameraBrowser</code>](#CameraBrowser)  
<a name="CameraBrowser.EventName"></a>

## CameraBrowser.EventName : <code>enum</code>
**Kind**: static enum of [<code>CameraBrowser</code>](#CameraBrowser)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>CameraAdd</td><td><code>string</code></td><td><code>&quot;CameraAdd&quot;</code></td>
    </tr><tr>
    <td>CameraConnect</td><td><code>string</code></td><td><code>&quot;CameraConnect&quot;</code></td>
    </tr><tr>
    <td>CameraDisconnect</td><td><code>string</code></td><td><code>&quot;CameraDisconnect&quot;</code></td>
    </tr><tr>
    <td>CameraRemove</td><td><code>string</code></td><td><code>&quot;CameraRemove&quot;</code></td>
    </tr><tr>
    <td>DirectoryCreate</td><td><code>string</code></td><td><code>&quot;DirectoryCreate&quot;</code></td>
    </tr><tr>
    <td>DownloadRequest</td><td><code>string</code></td><td><code>&quot;DownloadRequest&quot;</code></td>
    </tr><tr>
    <td>Error</td><td><code>string</code></td><td><code>&quot;Error&quot;</code></td>
    </tr><tr>
    <td>FileCreate</td><td><code>string</code></td><td><code>&quot;FileCreate&quot;</code></td>
    </tr><tr>
    <td>KeepAlive</td><td><code>string</code></td><td><code>&quot;KeepAlive&quot;</code></td>
    </tr><tr>
    <td>LiveViewStart</td><td><code>string</code></td><td><code>&quot;LiveViewStart&quot;</code></td>
    </tr><tr>
    <td>LiveViewStop</td><td><code>string</code></td><td><code>&quot;LiveViewStop&quot;</code></td>
    </tr><tr>
    <td>ObjectChange</td><td><code>string</code></td><td><code>&quot;ObjectChange&quot;</code></td>
    </tr><tr>
    <td>PropertyChangeOptions</td><td><code>string</code></td><td><code>&quot;PropertyChangeOptions&quot;</code></td>
    </tr><tr>
    <td>PropertyChangeValue</td><td><code>string</code></td><td><code>&quot;PropertyChangeValue&quot;</code></td>
    </tr><tr>
    <td>StateChange</td><td><code>string</code></td><td><code>&quot;StateChange&quot;</code></td>
    </tr><tr>
    <td>VolumeChange</td><td><code>string</code></td><td><code>&quot;VolumeChange&quot;</code></td>
    </tr>  </tbody>
</table>

<a name="CameraFile"></a>

# CameraFile
**Kind**: global class  
**Implements**: [<code>DirectoryEntry</code>](#DirectoryEntry)  

* [CameraFile](#CameraFile)
    * [new CameraFile()](#new_CameraFile_new)
    * [.name](#CameraFile+name)
    * [.localFile](#CameraFile+localFile)
    * [.groupID](#CameraFile+groupID)
    * [.size](#CameraFile+size)
    * [.format](#CameraFile+format)
    * [.downloadToPath(path)](#CameraFile+downloadToPath) ⇒ <code>string</code>
    * [.downloadToFile(fileName)](#CameraFile+downloadToFile) ⇒ <code>string</code>
    * [.downloadToString()](#CameraFile+downloadToString) ⇒ <code>string</code>
    * [.downloadThumbnailToString()](#CameraFile+downloadThumbnailToString) ⇒ <code>string</code>

<a name="new_CameraFile_new"></a>

## new CameraFile()
Provided in the [DownloadRequestEvent](DownloadRequestEvent). Allows to download the file from camera.

<a name="CameraFile+name"></a>

## cameraFile.name
Camera provided file name (without path)

**Kind**: instance property of [<code>CameraFile</code>](#CameraFile)  
**Read only**: true  
<a name="CameraFile+localFile"></a>

## cameraFile.localFile
Local file name including path after download.

**Kind**: instance property of [<code>CameraFile</code>](#CameraFile)  
**Read only**: true  
<a name="CameraFile+groupID"></a>

## cameraFile.groupID
Multiple formats of the same picture share an ID

**Kind**: instance property of [<code>CameraFile</code>](#CameraFile)  
**Read only**: true  
<a name="CameraFile+size"></a>

## cameraFile.size
File/image size in bytes

**Kind**: instance property of [<code>CameraFile</code>](#CameraFile)  
**Read only**: true  
<a name="CameraFile+format"></a>

## cameraFile.format
Format

**Kind**: instance property of [<code>CameraFile</code>](#CameraFile)  
**Read only**: true  
<a name="CameraFile+downloadToPath"></a>

## cameraFile.downloadToPath(path) ⇒ <code>string</code>
Download into a path using camera provided file name

**Kind**: instance method of [<code>CameraFile</code>](#CameraFile)  
**Returns**: <code>string</code> - local file name  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>path</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="CameraFile+downloadToFile"></a>

## cameraFile.downloadToFile(fileName) ⇒ <code>string</code>
Download into a specific file

**Kind**: instance method of [<code>CameraFile</code>](#CameraFile)  
**Returns**: <code>string</code> - local file name  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>fileName</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="CameraFile+downloadToString"></a>

## cameraFile.downloadToString() ⇒ <code>string</code>
Download into a base64 encoded string

**Kind**: instance method of [<code>CameraFile</code>](#CameraFile)  
**Returns**: <code>string</code> - base64 encoded string  
<a name="CameraFile+downloadThumbnailToString"></a>

## cameraFile.downloadThumbnailToString() ⇒ <code>string</code>
Download thumbnail into a base64 encoded string

**Kind**: instance method of [<code>CameraFile</code>](#CameraFile)  
**Returns**: <code>string</code> - base64 encoded string  
<a name="CameraProperty"></a>

# CameraProperty
**Kind**: global class  

* [CameraProperty](#CameraProperty)
    * [new CameraProperty(camera, propertyID, [propertySpecifier])](#new_CameraProperty_new)
    * _instance_
        * [.label](#CameraProperty+label) : <code>string</code>
        * [.identifier](#CameraProperty+identifier) : <code>number</code>
        * [.specifier](#CameraProperty+specifier) : <code>number</code>
        * [.available](#CameraProperty+available) : <code>boolean</code>
        * [.value](#CameraProperty+value) : [<code>CameraPropertyValue</code>](#CameraPropertyValue)
        * [.allowedValues](#CameraProperty+allowedValues) : [<code>Array.&lt;CameraPropertyValue&gt;</code>](#CameraPropertyValue)
        * [.toJSON()](#CameraProperty+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.ID](#CameraProperty.ID) : <code>enum</code>

<a name="new_CameraProperty_new"></a>

## new CameraProperty(camera, propertyID, [propertySpecifier])
Camera property/setting.

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>camera</td><td><code><a href="#Camera">Camera</a></code></td><td></td>
    </tr><tr>
    <td>propertyID</td><td><code>number</code></td><td></td>
    </tr><tr>
    <td>[propertySpecifier]</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

**Example**  

```typescriptconst property = camera.getProperty(Property.ID.Av);console.log(property.value, property.allowedValues);```

<a name="CameraProperty+label"></a>

## cameraProperty.label : <code>string</code>
**Kind**: instance property of [<code>CameraProperty</code>](#CameraProperty)  
**Read only**: true  
<a name="CameraProperty+identifier"></a>

## cameraProperty.identifier : <code>number</code>
**Kind**: instance property of [<code>CameraProperty</code>](#CameraProperty)  
**Read only**: true  
<a name="CameraProperty+specifier"></a>

## cameraProperty.specifier : <code>number</code>
**Kind**: instance property of [<code>CameraProperty</code>](#CameraProperty)  
**Read only**: true  
<a name="CameraProperty+available"></a>

## cameraProperty.available : <code>boolean</code>
**Kind**: instance property of [<code>CameraProperty</code>](#CameraProperty)  
**Read only**: true  
<a name="CameraProperty+value"></a>

## cameraProperty.value : [<code>CameraPropertyValue</code>](#CameraPropertyValue)
**Kind**: instance property of [<code>CameraProperty</code>](#CameraProperty)  
<a name="CameraProperty+allowedValues"></a>

## cameraProperty.allowedValues : [<code>Array.&lt;CameraPropertyValue&gt;</code>](#CameraPropertyValue)
**Kind**: instance property of [<code>CameraProperty</code>](#CameraProperty)  
<a name="CameraProperty+toJSON"></a>

## cameraProperty.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>CameraProperty</code>](#CameraProperty)  
<a name="CameraProperty.ID"></a>

## CameraProperty.ID : <code>enum</code>
**Kind**: static enum of [<code>CameraProperty</code>](#CameraProperty)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>AEBracket</td><td><code>number</code></td><td><code>1038</code></td>
    </tr><tr>
    <td>AEMode</td><td><code>number</code></td><td><code>1024</code></td>
    </tr><tr>
    <td>AEModeSelect</td><td><code>number</code></td><td><code>1078</code></td>
    </tr><tr>
    <td>AFMode</td><td><code>number</code></td><td><code>1028</code></td>
    </tr><tr>
    <td>Artist</td><td><code>number</code></td><td><code>1048</code></td>
    </tr><tr>
    <td>AutoPowerOffSetting</td><td><code>number</code></td><td><code>16778334</code></td>
    </tr><tr>
    <td>Av</td><td><code>number</code></td><td><code>1029</code></td>
    </tr><tr>
    <td>AvailableShots</td><td><code>number</code></td><td><code>1034</code></td>
    </tr><tr>
    <td>BatteryLevel</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>BatteryQuality</td><td><code>number</code></td><td><code>16</code></td>
    </tr><tr>
    <td>BodyIDEx</td><td><code>number</code></td><td><code>21</code></td>
    </tr><tr>
    <td>Bracket</td><td><code>number</code></td><td><code>1035</code></td>
    </tr><tr>
    <td>CFn</td><td><code>number</code></td><td><code>9</code></td>
    </tr><tr>
    <td>ColorSpace</td><td><code>number</code></td><td><code>269</code></td>
    </tr><tr>
    <td>ColorTemperature</td><td><code>number</code></td><td><code>263</code></td>
    </tr><tr>
    <td>Copyright</td><td><code>number</code></td><td><code>1049</code></td>
    </tr><tr>
    <td>CurrentFolder</td><td><code>number</code></td><td><code>13</code></td>
    </tr><tr>
    <td>CurrentStorage</td><td><code>number</code></td><td><code>12</code></td>
    </tr><tr>
    <td>DC_Strobe</td><td><code>number</code></td><td><code>1537</code></td>
    </tr><tr>
    <td>DC_Zoom</td><td><code>number</code></td><td><code>1536</code></td>
    </tr><tr>
    <td>DateTime</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>DepthOfField</td><td><code>number</code></td><td><code>1051</code></td>
    </tr><tr>
    <td>DriveMode</td><td><code>number</code></td><td><code>1025</code></td>
    </tr><tr>
    <td>EFCompensation</td><td><code>number</code></td><td><code>1054</code></td>
    </tr><tr>
    <td>EVF_RollingPitching</td><td><code>number</code></td><td><code>16778564</code></td>
    </tr><tr>
    <td>Evf_AFMode</td><td><code>number</code></td><td><code>1294</code></td>
    </tr><tr>
    <td>Evf_ClickWBCoeffs</td><td><code>number</code></td><td><code>16778502</code></td>
    </tr><tr>
    <td>Evf_ColorTemperature</td><td><code>number</code></td><td><code>1283</code></td>
    </tr><tr>
    <td>Evf_CoordinateSystem</td><td><code>number</code></td><td><code>1344</code></td>
    </tr><tr>
    <td>Evf_DepthOfFieldPreview</td><td><code>number</code></td><td><code>1284</code></td>
    </tr><tr>
    <td>Evf_FocusAid</td><td><code>number</code></td><td><code>1289</code></td>
    </tr><tr>
    <td>Evf_Histogram</td><td><code>number</code></td><td><code>1290</code></td>
    </tr><tr>
    <td>Evf_HistogramB</td><td><code>number</code></td><td><code>1304</code></td>
    </tr><tr>
    <td>Evf_HistogramG</td><td><code>number</code></td><td><code>1303</code></td>
    </tr><tr>
    <td>Evf_HistogramR</td><td><code>number</code></td><td><code>1302</code></td>
    </tr><tr>
    <td>Evf_HistogramStatus</td><td><code>number</code></td><td><code>1292</code></td>
    </tr><tr>
    <td>Evf_HistogramY</td><td><code>number</code></td><td><code>1301</code></td>
    </tr><tr>
    <td>Evf_ImageClipRect</td><td><code>number</code></td><td><code>1349</code></td>
    </tr><tr>
    <td>Evf_ImagePosition</td><td><code>number</code></td><td><code>1291</code></td>
    </tr><tr>
    <td>Evf_Mode</td><td><code>number</code></td><td><code>1281</code></td>
    </tr><tr>
    <td>Evf_OutputDevice</td><td><code>number</code></td><td><code>1280</code></td>
    </tr><tr>
    <td>Evf_PowerZoom_CurPosition</td><td><code>number</code></td><td><code>1360</code></td>
    </tr><tr>
    <td>Evf_PowerZoom_MaxPosition</td><td><code>number</code></td><td><code>1361</code></td>
    </tr><tr>
    <td>Evf_PowerZoom_MinPosition</td><td><code>number</code></td><td><code>1362</code></td>
    </tr><tr>
    <td>Evf_WhiteBalance</td><td><code>number</code></td><td><code>1282</code></td>
    </tr><tr>
    <td>Evf_Zoom</td><td><code>number</code></td><td><code>1287</code></td>
    </tr><tr>
    <td>Evf_ZoomPosition</td><td><code>number</code></td><td><code>1288</code></td>
    </tr><tr>
    <td>Evf_ZoomRect</td><td><code>number</code></td><td><code>1345</code></td>
    </tr><tr>
    <td>ExposureCompensation</td><td><code>number</code></td><td><code>1031</code></td>
    </tr><tr>
    <td>FEBracket</td><td><code>number</code></td><td><code>1039</code></td>
    </tr><tr>
    <td>FirmwareVersion</td><td><code>number</code></td><td><code>7</code></td>
    </tr><tr>
    <td>FixedMovie</td><td><code>number</code></td><td><code>16778274</code></td>
    </tr><tr>
    <td>FlashCompensation</td><td><code>number</code></td><td><code>1032</code></td>
    </tr><tr>
    <td>FlashMode</td><td><code>number</code></td><td><code>1044</code></td>
    </tr><tr>
    <td>FlashOn</td><td><code>number</code></td><td><code>1042</code></td>
    </tr><tr>
    <td>FocalLength</td><td><code>number</code></td><td><code>1033</code></td>
    </tr><tr>
    <td>FocusInfo</td><td><code>number</code></td><td><code>260</code></td>
    </tr><tr>
    <td>GPSAltitude</td><td><code>number</code></td><td><code>2054</code></td>
    </tr><tr>
    <td>GPSAltitudeRef</td><td><code>number</code></td><td><code>2053</code></td>
    </tr><tr>
    <td>GPSDateStamp</td><td><code>number</code></td><td><code>2077</code></td>
    </tr><tr>
    <td>GPSLatitude</td><td><code>number</code></td><td><code>2050</code></td>
    </tr><tr>
    <td>GPSLatitudeRef</td><td><code>number</code></td><td><code>2049</code></td>
    </tr><tr>
    <td>GPSLongitude</td><td><code>number</code></td><td><code>2052</code></td>
    </tr><tr>
    <td>GPSLongitudeRef</td><td><code>number</code></td><td><code>2051</code></td>
    </tr><tr>
    <td>GPSMapDatum</td><td><code>number</code></td><td><code>2066</code></td>
    </tr><tr>
    <td>GPSSatellites</td><td><code>number</code></td><td><code>2056</code></td>
    </tr><tr>
    <td>GPSStatus</td><td><code>number</code></td><td><code>2057</code></td>
    </tr><tr>
    <td>GPSTimeStamp</td><td><code>number</code></td><td><code>2055</code></td>
    </tr><tr>
    <td>GPSVersionID</td><td><code>number</code></td><td><code>2048</code></td>
    </tr><tr>
    <td>HDDirectoryStructure</td><td><code>number</code></td><td><code>32</code></td>
    </tr><tr>
    <td>ICCProfile</td><td><code>number</code></td><td><code>259</code></td>
    </tr><tr>
    <td>ISOBracket</td><td><code>number</code></td><td><code>1040</code></td>
    </tr><tr>
    <td>ISOSpeed</td><td><code>number</code></td><td><code>1026</code></td>
    </tr><tr>
    <td>ImageQuality</td><td><code>number</code></td><td><code>256</code></td>
    </tr><tr>
    <td>JpegQuality</td><td><code>number</code></td><td><code>257</code></td>
    </tr><tr>
    <td>LensBarrelStatus</td><td><code>number</code></td><td><code>1541</code></td>
    </tr><tr>
    <td>LensName</td><td><code>number</code></td><td><code>1037</code></td>
    </tr><tr>
    <td>LensStatus</td><td><code>number</code></td><td><code>1046</code></td>
    </tr><tr>
    <td>MakerName</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>ManualWhiteBalanceData</td><td><code>number</code></td><td><code>16777732</code></td>
    </tr><tr>
    <td>MeteringMode</td><td><code>number</code></td><td><code>1027</code></td>
    </tr><tr>
    <td>MirrorLockUpState</td><td><code>number</code></td><td><code>16778273</code></td>
    </tr><tr>
    <td>MirrorUpSetting</td><td><code>number</code></td><td><code>16778296</code></td>
    </tr><tr>
    <td>MovieParam</td><td><code>number</code></td><td><code>16778275</code></td>
    </tr><tr>
    <td>MyMenu</td><td><code>number</code></td><td><code>14</code></td>
    </tr><tr>
    <td>NoiseReduction</td><td><code>number</code></td><td><code>1041</code></td>
    </tr><tr>
    <td>Orientation</td><td><code>number</code></td><td><code>258</code></td>
    </tr><tr>
    <td>OwnerName</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>PictureStyle</td><td><code>number</code></td><td><code>276</code></td>
    </tr><tr>
    <td>PictureStyleCaption</td><td><code>number</code></td><td><code>512</code></td>
    </tr><tr>
    <td>PictureStyleDescription</td><td><code>number</code></td><td><code>277</code></td>
    </tr><tr>
    <td>PowerZoom_Speed</td><td><code>number</code></td><td><code>1092</code></td>
    </tr><tr>
    <td>ProductName</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>Record</td><td><code>number</code></td><td><code>1296</code></td>
    </tr><tr>
    <td>RedEye</td><td><code>number</code></td><td><code>1043</code></td>
    </tr><tr>
    <td>SaveTo</td><td><code>number</code></td><td><code>11</code></td>
    </tr><tr>
    <td>SummerTimeSetting</td><td><code>number</code></td><td><code>16777240</code></td>
    </tr><tr>
    <td>TemperatureStatus</td><td><code>number</code></td><td><code>16778261</code></td>
    </tr><tr>
    <td>TimeZone</td><td><code>number</code></td><td><code>16777239</code></td>
    </tr><tr>
    <td>Tv</td><td><code>number</code></td><td><code>1030</code></td>
    </tr><tr>
    <td>UTCTime</td><td><code>number</code></td><td><code>16777238</code></td>
    </tr><tr>
    <td>WhiteBalance</td><td><code>number</code></td><td><code>262</code></td>
    </tr><tr>
    <td>WhiteBalanceBracket</td><td><code>number</code></td><td><code>1036</code></td>
    </tr><tr>
    <td>WhiteBalanceShift</td><td><code>number</code></td><td><code>264</code></td>
    </tr>  </tbody>
</table>

<a name="Directory"></a>

# Directory
**Kind**: global class  
**Implements**: [<code>DirectoryEntry</code>](#DirectoryEntry)  

* [Directory](#Directory)
    * [.name](#Directory+name) ⇒ <code>string</code>
    * [.length](#Directory+length) ⇒ <code>number</code>
    * [.getEntries()](#Directory+getEntries) ⇒ [<code>Array.&lt;DirectoryEntry&gt;</code>](#DirectoryEntry)

<a name="Directory+name"></a>

## directory.name ⇒ <code>string</code>
**Kind**: instance property of [<code>Directory</code>](#Directory)  
**Read only**: true  
<a name="Directory+length"></a>

## directory.length ⇒ <code>number</code>
Entry count

**Kind**: instance property of [<code>Directory</code>](#Directory)  
<a name="Directory+getEntries"></a>

## directory.getEntries() ⇒ [<code>Array.&lt;DirectoryEntry&gt;</code>](#DirectoryEntry)
**Kind**: instance method of [<code>Directory</code>](#Directory)  
<a name="ExposureCompensation"></a>

# ExposureCompensation
**Kind**: global class  

* [ExposureCompensation](#ExposureCompensation)
    * [new ExposureCompensation(value_)](#new_ExposureCompensation_new)
    * _instance_
        * [.label](#ExposureCompensation+label) : <code>string</code>
        * [.value](#ExposureCompensation+value) : <code>number</code>
        * [.compensation](#ExposureCompensation+compensation) : <code>number</code>
    * _static_
        * [.Values](#ExposureCompensation.Values) : <code>enum</code>
        * [.forLabel(label)](#ExposureCompensation.forLabel) ⇒ [<code>ExposureCompensation</code>](#ExposureCompensation) \| <code>null</code>

<a name="new_ExposureCompensation_new"></a>

## new ExposureCompensation(value_)
Encapsulate Object for a exposure compensation value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value_</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="ExposureCompensation+label"></a>

## exposureCompensation.label : <code>string</code>
**Kind**: instance property of [<code>ExposureCompensation</code>](#ExposureCompensation)  
**Read only**: true  
<a name="ExposureCompensation+value"></a>

## exposureCompensation.value : <code>number</code>
**Kind**: instance property of [<code>ExposureCompensation</code>](#ExposureCompensation)  
**Read only**: true  
<a name="ExposureCompensation+compensation"></a>

## exposureCompensation.compensation : <code>number</code>
**Kind**: instance property of [<code>ExposureCompensation</code>](#ExposureCompensation)  
**Read only**: true  
<a name="ExposureCompensation.Values"></a>

## ExposureCompensation.Values : <code>enum</code>
**Kind**: static enum of [<code>ExposureCompensation</code>](#ExposureCompensation)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>0</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>3</td><td><code>number</code></td><td><code>0.3333333333333333</code></td>
    </tr><tr>
    <td>4</td><td><code>number</code></td><td><code>0.5</code></td>
    </tr><tr>
    <td>5</td><td><code>number</code></td><td><code>0.6666666666666666</code></td>
    </tr><tr>
    <td>8</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>11</td><td><code>number</code></td><td><code>1.3333333333333333</code></td>
    </tr><tr>
    <td>12</td><td><code>number</code></td><td><code>1.5</code></td>
    </tr><tr>
    <td>13</td><td><code>number</code></td><td><code>1.6666666666666665</code></td>
    </tr><tr>
    <td>16</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>19</td><td><code>number</code></td><td><code>2.3333333333333335</code></td>
    </tr><tr>
    <td>20</td><td><code>number</code></td><td><code>2.5</code></td>
    </tr><tr>
    <td>21</td><td><code>number</code></td><td><code>2.6666666666666665</code></td>
    </tr><tr>
    <td>24</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>27</td><td><code>number</code></td><td><code>3.3333333333333335</code></td>
    </tr><tr>
    <td>28</td><td><code>number</code></td><td><code>3.5</code></td>
    </tr><tr>
    <td>29</td><td><code>number</code></td><td><code>3.6666666666666665</code></td>
    </tr><tr>
    <td>32</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>35</td><td><code>number</code></td><td><code>4.333333333333333</code></td>
    </tr><tr>
    <td>36</td><td><code>number</code></td><td><code>4.5</code></td>
    </tr><tr>
    <td>37</td><td><code>number</code></td><td><code>4.666666666666667</code></td>
    </tr><tr>
    <td>40</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>216</td><td><code>number</code></td><td><code>-5</code></td>
    </tr><tr>
    <td>219</td><td><code>number</code></td><td><code>-4.666666666666667</code></td>
    </tr><tr>
    <td>220</td><td><code>number</code></td><td><code>-4.5</code></td>
    </tr><tr>
    <td>221</td><td><code>number</code></td><td><code>-4.333333333333333</code></td>
    </tr><tr>
    <td>224</td><td><code>number</code></td><td><code>-4</code></td>
    </tr><tr>
    <td>227</td><td><code>number</code></td><td><code>-3.6666666666666665</code></td>
    </tr><tr>
    <td>228</td><td><code>number</code></td><td><code>-3.5</code></td>
    </tr><tr>
    <td>229</td><td><code>number</code></td><td><code>-3.3333333333333335</code></td>
    </tr><tr>
    <td>232</td><td><code>number</code></td><td><code>-3</code></td>
    </tr><tr>
    <td>235</td><td><code>number</code></td><td><code>-2.6666666666666665</code></td>
    </tr><tr>
    <td>236</td><td><code>number</code></td><td><code>-2.5</code></td>
    </tr><tr>
    <td>237</td><td><code>number</code></td><td><code>-2.3333333333333335</code></td>
    </tr><tr>
    <td>240</td><td><code>number</code></td><td><code>-2</code></td>
    </tr><tr>
    <td>243</td><td><code>number</code></td><td><code>-1.6666666666666665</code></td>
    </tr><tr>
    <td>244</td><td><code>number</code></td><td><code>-1.5</code></td>
    </tr><tr>
    <td>245</td><td><code>number</code></td><td><code>-1.3333333333333333</code></td>
    </tr><tr>
    <td>248</td><td><code>number</code></td><td><code>-1</code></td>
    </tr><tr>
    <td>251</td><td><code>number</code></td><td><code>-0.6666666666666666</code></td>
    </tr><tr>
    <td>252</td><td><code>number</code></td><td><code>-0.5</code></td>
    </tr><tr>
    <td>253</td><td><code>number</code></td><td><code>-0.3333333333333333</code></td>
    </tr>  </tbody>
</table>

<a name="ExposureCompensation.forLabel"></a>

## ExposureCompensation.forLabel(label) ⇒ [<code>ExposureCompensation</code>](#ExposureCompensation) \| <code>null</code>
Create instance for label.

**Kind**: static method of [<code>ExposureCompensation</code>](#ExposureCompensation)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>label</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="FileFormat"></a>

# FileFormat
**Kind**: global class  

* [FileFormat](#FileFormat)
    * [new FileFormat(value_)](#new_FileFormat_new)
    * _instance_
        * [.label](#FileFormat+label) : <code>string</code>
        * [.value](#FileFormat+value) : <code>number</code>
    * _static_
        * [.ID](#FileFormat.ID) : <code>enum</code>

<a name="new_FileFormat_new"></a>

## new FileFormat(value_)
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value_</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="FileFormat+label"></a>

## fileFormat.label : <code>string</code>
**Kind**: instance property of [<code>FileFormat</code>](#FileFormat)  
**Read only**: true  
<a name="FileFormat+value"></a>

## fileFormat.value : <code>number</code>
**Kind**: instance property of [<code>FileFormat</code>](#FileFormat)  
**Read only**: true  
<a name="FileFormat.ID"></a>

## FileFormat.ID : <code>enum</code>
**Kind**: static enum of [<code>FileFormat</code>](#FileFormat)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>CR2</td><td><code>number</code></td><td><code>45315</code></td>
    </tr><tr>
    <td>CR3</td><td><code>number</code></td><td><code>45320</code></td>
    </tr><tr>
    <td>HEIF_CODE</td><td><code>number</code></td><td><code>45323</code></td>
    </tr><tr>
    <td>JPEG</td><td><code>number</code></td><td><code>14337</code></td>
    </tr><tr>
    <td>MP4</td><td><code>number</code></td><td><code>47490</code></td>
    </tr><tr>
    <td>Unknown</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Flag"></a>

# Flag
**Kind**: global class  

* [Flag](#Flag)
    * [new Flag(value)](#new_Flag_new)
    * [new Flag(value)](#new_Flag_new)
    * _instance_
        * [.label](#Flag+label) : <code>string</code>
        * [.value](#Flag+value) : <code>number</code>
        * [.flag](#Flag+flag) : <code>boolean</code>
        * [.toJSON()](#Flag+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.True](#Flag.True) : <code>number</code>
        * [.False](#Flag.False) : <code>number</code>
        * [.forLabel(label)](#Flag.forLabel) ⇒ [<code>Flag</code>](#Flag)

<a name="new_Flag_new"></a>

## new Flag(value)
Boolean property value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value</td><td><code>number</code> | <code>boolean</code></td>
    </tr>  </tbody>
</table>

<a name="new_Flag_new"></a>

## new Flag(value)
Boolean property value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value</td><td><code>number</code> | <code>boolean</code></td>
    </tr>  </tbody>
</table>

<a name="Flag+label"></a>

## flag.label : <code>string</code>
**Kind**: instance property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag+value"></a>

## flag.value : <code>number</code>
**Kind**: instance property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag+flag"></a>

## flag.flag : <code>boolean</code>
**Kind**: instance property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag+toJSON"></a>

## flag.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>Flag</code>](#Flag)  
<a name="Flag.True"></a>

## Flag.True : <code>number</code>
**Kind**: static property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag.False"></a>

## Flag.False : <code>number</code>
**Kind**: static property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag.forLabel"></a>

## Flag.forLabel(label) ⇒ [<code>Flag</code>](#Flag)
Create instance for label.

**Kind**: static method of [<code>Flag</code>](#Flag)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>label</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="ImageQuality"></a>

# ImageQuality
**Kind**: global class  

* [ImageQuality](#ImageQuality)
    * [new ImageQuality(value_)](#new_ImageQuality_new)
    * _instance_
        * [.label](#ImageQuality+label) : <code>string</code>
        * [.value](#ImageQuality+value) : <code>number</code>
        * [.main](#ImageQuality+main) : [<code>ImageQualityProperties</code>](#ImageQualityProperties)
        * [.secondary](#ImageQuality+secondary) : [<code>ImageQualityProperties</code>](#ImageQualityProperties)
    * _static_
        * [.ID](#ImageQuality.ID) : <code>enum</code>
        * [.Format](#ImageQuality.Format) : <code>enum</code>
        * [.Size](#ImageQuality.Size) : <code>enum</code>
        * [.CompressionQuality](#ImageQuality.CompressionQuality) : <code>enum</code>

<a name="new_ImageQuality_new"></a>

## new ImageQuality(value_)
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value_</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="ImageQuality+label"></a>

## imageQuality.label : <code>string</code>
**Kind**: instance property of [<code>ImageQuality</code>](#ImageQuality)  
**Read only**: true  
<a name="ImageQuality+value"></a>

## imageQuality.value : <code>number</code>
**Kind**: instance property of [<code>ImageQuality</code>](#ImageQuality)  
**Read only**: true  
<a name="ImageQuality+main"></a>

## imageQuality.main : [<code>ImageQualityProperties</code>](#ImageQualityProperties)
**Kind**: instance property of [<code>ImageQuality</code>](#ImageQuality)  
**Read only**: true  
<a name="ImageQuality+secondary"></a>

## imageQuality.secondary : [<code>ImageQualityProperties</code>](#ImageQualityProperties)
**Kind**: instance property of [<code>ImageQuality</code>](#ImageQuality)  
**Read only**: true  
<a name="ImageQuality.ID"></a>

## ImageQuality.ID : <code>enum</code>
**Kind**: static enum of [<code>ImageQuality</code>](#ImageQuality)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>CR</td><td><code>number</code></td><td><code>6553359</code></td>
    </tr><tr>
    <td>CRHEIFL</td><td><code>number</code></td><td><code>6488192</code></td>
    </tr><tr>
    <td>CRHEIFLF</td><td><code>number</code></td><td><code>6488195</code></td>
    </tr><tr>
    <td>CRHEIFLN</td><td><code>number</code></td><td><code>6488194</code></td>
    </tr><tr>
    <td>CRHEIFMF</td><td><code>number</code></td><td><code>6488451</code></td>
    </tr><tr>
    <td>CRHEIFMN</td><td><code>number</code></td><td><code>6488450</code></td>
    </tr><tr>
    <td>CRHEIFS1F</td><td><code>number</code></td><td><code>6491779</code></td>
    </tr><tr>
    <td>CRHEIFS1N</td><td><code>number</code></td><td><code>6491778</code></td>
    </tr><tr>
    <td>CRHEIFS2F</td><td><code>number</code></td><td><code>6492035</code></td>
    </tr><tr>
    <td>CRLJ</td><td><code>number</code></td><td><code>6488080</code></td>
    </tr><tr>
    <td>CRLJF</td><td><code>number</code></td><td><code>6488083</code></td>
    </tr><tr>
    <td>CRLJN</td><td><code>number</code></td><td><code>6488082</code></td>
    </tr><tr>
    <td>CRM1J</td><td><code>number</code></td><td><code>6489360</code></td>
    </tr><tr>
    <td>CRM1JF</td><td><code>number</code></td><td><code>6489363</code></td>
    </tr><tr>
    <td>CRM1JN</td><td><code>number</code></td><td><code>6489362</code></td>
    </tr><tr>
    <td>CRM2J</td><td><code>number</code></td><td><code>6489616</code></td>
    </tr><tr>
    <td>CRM2JF</td><td><code>number</code></td><td><code>6489619</code></td>
    </tr><tr>
    <td>CRM2JN</td><td><code>number</code></td><td><code>6489618</code></td>
    </tr><tr>
    <td>CRMJ</td><td><code>number</code></td><td><code>6488336</code></td>
    </tr><tr>
    <td>CRMJF</td><td><code>number</code></td><td><code>6488339</code></td>
    </tr><tr>
    <td>CRMJN</td><td><code>number</code></td><td><code>6488338</code></td>
    </tr><tr>
    <td>CRS1J</td><td><code>number</code></td><td><code>6491664</code></td>
    </tr><tr>
    <td>CRS1JF</td><td><code>number</code></td><td><code>6491667</code></td>
    </tr><tr>
    <td>CRS1JN</td><td><code>number</code></td><td><code>6491666</code></td>
    </tr><tr>
    <td>CRS2J</td><td><code>number</code></td><td><code>6491920</code></td>
    </tr><tr>
    <td>CRS2JF</td><td><code>number</code></td><td><code>6491923</code></td>
    </tr><tr>
    <td>CRS3JF</td><td><code>number</code></td><td><code>6492179</code></td>
    </tr><tr>
    <td>CRSJ</td><td><code>number</code></td><td><code>6488592</code></td>
    </tr><tr>
    <td>CRSJF</td><td><code>number</code></td><td><code>6488595</code></td>
    </tr><tr>
    <td>CRSJN</td><td><code>number</code></td><td><code>6488594</code></td>
    </tr><tr>
    <td>HEIFL</td><td><code>number</code></td><td><code>8453903</code></td>
    </tr><tr>
    <td>HEIFLF</td><td><code>number</code></td><td><code>8650511</code></td>
    </tr><tr>
    <td>HEIFLN</td><td><code>number</code></td><td><code>8584975</code></td>
    </tr><tr>
    <td>HEIFMF</td><td><code>number</code></td><td><code>25427727</code></td>
    </tr><tr>
    <td>HEIFMN</td><td><code>number</code></td><td><code>25362191</code></td>
    </tr><tr>
    <td>HEIFS1F</td><td><code>number</code></td><td><code>243531535</code></td>
    </tr><tr>
    <td>HEIFS1N</td><td><code>number</code></td><td><code>243465999</code></td>
    </tr><tr>
    <td>HEIFS2F</td><td><code>number</code></td><td><code>260308751</code></td>
    </tr><tr>
    <td>LargeJPEG</td><td><code>number</code></td><td><code>1113871</code></td>
    </tr><tr>
    <td>LargeJPEGFine</td><td><code>number</code></td><td><code>1310479</code></td>
    </tr><tr>
    <td>LargeJPEGNormal</td><td><code>number</code></td><td><code>1244943</code></td>
    </tr><tr>
    <td>MR</td><td><code>number</code></td><td><code>23396111</code></td>
    </tr><tr>
    <td>MRLJ</td><td><code>number</code></td><td><code>23330832</code></td>
    </tr><tr>
    <td>MRLJF</td><td><code>number</code></td><td><code>23330835</code></td>
    </tr><tr>
    <td>MRLJN</td><td><code>number</code></td><td><code>23330834</code></td>
    </tr><tr>
    <td>MRM1J</td><td><code>number</code></td><td><code>23332112</code></td>
    </tr><tr>
    <td>MRM2J</td><td><code>number</code></td><td><code>23332368</code></td>
    </tr><tr>
    <td>MRMJF</td><td><code>number</code></td><td><code>23331091</code></td>
    </tr><tr>
    <td>MRMJN</td><td><code>number</code></td><td><code>23331090</code></td>
    </tr><tr>
    <td>MRS1JF</td><td><code>number</code></td><td><code>23334419</code></td>
    </tr><tr>
    <td>MRS1JN</td><td><code>number</code></td><td><code>23334418</code></td>
    </tr><tr>
    <td>MRS2JF</td><td><code>number</code></td><td><code>23334675</code></td>
    </tr><tr>
    <td>MRS3JF</td><td><code>number</code></td><td><code>23334931</code></td>
    </tr><tr>
    <td>MRSJ</td><td><code>number</code></td><td><code>23331344</code></td>
    </tr><tr>
    <td>MRSJF</td><td><code>number</code></td><td><code>23331347</code></td>
    </tr><tr>
    <td>MRSJN</td><td><code>number</code></td><td><code>23331346</code></td>
    </tr><tr>
    <td>Middle1JPEG</td><td><code>number</code></td><td><code>84999951</code></td>
    </tr><tr>
    <td>Middle2JPEG</td><td><code>number</code></td><td><code>101777167</code></td>
    </tr><tr>
    <td>MiddleJPEG</td><td><code>number</code></td><td><code>17891087</code></td>
    </tr><tr>
    <td>MiddleJPEGFine</td><td><code>number</code></td><td><code>18087695</code></td>
    </tr><tr>
    <td>MiddleJPEGNormal</td><td><code>number</code></td><td><code>18022159</code></td>
    </tr><tr>
    <td>RAW</td><td><code>number</code></td><td><code>6618895</code></td>
    </tr><tr>
    <td>RAWAndLargeJPEG</td><td><code>number</code></td><td><code>6553616</code></td>
    </tr><tr>
    <td>RAWAndLargeJPEGFine</td><td><code>number</code></td><td><code>6553619</code></td>
    </tr><tr>
    <td>RAWAndLargeJPEGNormal</td><td><code>number</code></td><td><code>6553618</code></td>
    </tr><tr>
    <td>RAWAndMiddle1JPEG</td><td><code>number</code></td><td><code>6554896</code></td>
    </tr><tr>
    <td>RAWAndMiddle2JPEG</td><td><code>number</code></td><td><code>6555152</code></td>
    </tr><tr>
    <td>RAWAndMiddleJPEG</td><td><code>number</code></td><td><code>6553872</code></td>
    </tr><tr>
    <td>RAWAndMiddleJPEGFine</td><td><code>number</code></td><td><code>6553875</code></td>
    </tr><tr>
    <td>RAWAndMiddleJPEGNormal</td><td><code>number</code></td><td><code>6553874</code></td>
    </tr><tr>
    <td>RAWAndSmall1JPEG</td><td><code>number</code></td><td><code>6557200</code></td>
    </tr><tr>
    <td>RAWAndSmall1JPEGFine</td><td><code>number</code></td><td><code>6557203</code></td>
    </tr><tr>
    <td>RAWAndSmall1JPEGNormal</td><td><code>number</code></td><td><code>6557202</code></td>
    </tr><tr>
    <td>RAWAndSmall2JPEG</td><td><code>number</code></td><td><code>6557456</code></td>
    </tr><tr>
    <td>RAWAndSmall2JPEGFine</td><td><code>number</code></td><td><code>6557459</code></td>
    </tr><tr>
    <td>RAWAndSmall3JPEGFine</td><td><code>number</code></td><td><code>6557715</code></td>
    </tr><tr>
    <td>RAWAndSmallJPEG</td><td><code>number</code></td><td><code>6554128</code></td>
    </tr><tr>
    <td>RAWAndSmallJPEGFine</td><td><code>number</code></td><td><code>6554131</code></td>
    </tr><tr>
    <td>RAWAndSmallJPEGNormal</td><td><code>number</code></td><td><code>6554130</code></td>
    </tr><tr>
    <td>RHEIFL</td><td><code>number</code></td><td><code>6553728</code></td>
    </tr><tr>
    <td>RHEIFLF</td><td><code>number</code></td><td><code>6553731</code></td>
    </tr><tr>
    <td>RHEIFLN</td><td><code>number</code></td><td><code>6553730</code></td>
    </tr><tr>
    <td>RHEIFMF</td><td><code>number</code></td><td><code>6553987</code></td>
    </tr><tr>
    <td>RHEIFMN</td><td><code>number</code></td><td><code>6553986</code></td>
    </tr><tr>
    <td>RHEIFS1F</td><td><code>number</code></td><td><code>6557315</code></td>
    </tr><tr>
    <td>RHEIFS1N</td><td><code>number</code></td><td><code>6557314</code></td>
    </tr><tr>
    <td>RHEIFS2F</td><td><code>number</code></td><td><code>6557571</code></td>
    </tr><tr>
    <td>SR</td><td><code>number</code></td><td><code>40173327</code></td>
    </tr><tr>
    <td>SRLJ</td><td><code>number</code></td><td><code>40108048</code></td>
    </tr><tr>
    <td>SRLJF</td><td><code>number</code></td><td><code>40108051</code></td>
    </tr><tr>
    <td>SRLJN</td><td><code>number</code></td><td><code>40108050</code></td>
    </tr><tr>
    <td>SRM1J</td><td><code>number</code></td><td><code>40109328</code></td>
    </tr><tr>
    <td>SRM2J</td><td><code>number</code></td><td><code>40109584</code></td>
    </tr><tr>
    <td>SRMJF</td><td><code>number</code></td><td><code>40108307</code></td>
    </tr><tr>
    <td>SRMJN</td><td><code>number</code></td><td><code>40108306</code></td>
    </tr><tr>
    <td>SRS1JF</td><td><code>number</code></td><td><code>40111635</code></td>
    </tr><tr>
    <td>SRS1JN</td><td><code>number</code></td><td><code>40111634</code></td>
    </tr><tr>
    <td>SRS2JF</td><td><code>number</code></td><td><code>40111891</code></td>
    </tr><tr>
    <td>SRS3JF</td><td><code>number</code></td><td><code>40112147</code></td>
    </tr><tr>
    <td>SRSJ</td><td><code>number</code></td><td><code>40108560</code></td>
    </tr><tr>
    <td>SRSJF</td><td><code>number</code></td><td><code>40108563</code></td>
    </tr><tr>
    <td>SRSJN</td><td><code>number</code></td><td><code>40108562</code></td>
    </tr><tr>
    <td>Small1JPEGFine</td><td><code>number</code></td><td><code>236191503</code></td>
    </tr><tr>
    <td>Small1JPEGNormal</td><td><code>number</code></td><td><code>236125967</code></td>
    </tr><tr>
    <td>Small2JPEGFine</td><td><code>number</code></td><td><code>252968719</code></td>
    </tr><tr>
    <td>Small3JPEGFine</td><td><code>number</code></td><td><code>269745935</code></td>
    </tr><tr>
    <td>SmallJPEG</td><td><code>number</code></td><td><code>34668303</code></td>
    </tr><tr>
    <td>SmallJPEG1</td><td><code>number</code></td><td><code>235994895</code></td>
    </tr><tr>
    <td>SmallJPEG2</td><td><code>number</code></td><td><code>252772111</code></td>
    </tr><tr>
    <td>SmallJPEGFine</td><td><code>number</code></td><td><code>34864911</code></td>
    </tr><tr>
    <td>SmallJPEGNormal</td><td><code>number</code></td><td><code>34799375</code></td>
    </tr><tr>
    <td>Unknown</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr>  </tbody>
</table>

<a name="ImageQuality.Format"></a>

## ImageQuality.Format : <code>enum</code>
**Kind**: static enum of [<code>ImageQuality</code>](#ImageQuality)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>CR2</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>CRW</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>HEIF</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>JPEG</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>RAW</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>Unknown</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="ImageQuality.Size"></a>

## ImageQuality.Size : <code>enum</code>
**Kind**: static enum of [<code>ImageQuality</code>](#ImageQuality)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Large</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>Middle</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>Middle1</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>Middle2</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>Small</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>Small1</td><td><code>number</code></td><td><code>14</code></td>
    </tr><tr>
    <td>Small2</td><td><code>number</code></td><td><code>15</code></td>
    </tr><tr>
    <td>Small3</td><td><code>number</code></td><td><code>16</code></td>
    </tr><tr>
    <td>Unknown</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr>  </tbody>
</table>

<a name="ImageQuality.CompressionQuality"></a>

## ImageQuality.CompressionQuality : <code>enum</code>
**Kind**: static enum of [<code>ImageQuality</code>](#ImageQuality)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Fine</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>Lossless</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>Normal</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>SuperFine</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>Unknown</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr>  </tbody>
</table>

<a name="ISOSensitivity"></a>

# ISOSensitivity
**Kind**: global class  
**Implements**: [<code>PropertyValue</code>](#PropertyValue)  

* [ISOSensitivity](#ISOSensitivity)
    * [new ISOSensitivity(value_)](#new_ISOSensitivity_new)
    * _instance_
        * [.label](#ISOSensitivity+label) : <code>string</code>
        * [.value](#ISOSensitivity+value) : <code>number</code>
        * [.sensitivity](#ISOSensitivity+sensitivity) : <code>number</code>
        * [.toJSON()](#ISOSensitivity+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.ID](#ISOSensitivity.ID) : <code>enum</code>
        * [.Values](#ISOSensitivity.Values) : <code>enum</code>
        * [.forLabel(label)](#ISOSensitivity.forLabel) ⇒ [<code>ISOSensitivity</code>](#ISOSensitivity) \| <code>null</code>

<a name="new_ISOSensitivity_new"></a>

## new ISOSensitivity(value_)
ISO Sensitivity property value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value_</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="ISOSensitivity+label"></a>

## isoSensitivity.label : <code>string</code>
**Kind**: instance property of [<code>ISOSensitivity</code>](#ISOSensitivity)  
**Read only**: true  
<a name="ISOSensitivity+value"></a>

## isoSensitivity.value : <code>number</code>
**Kind**: instance property of [<code>ISOSensitivity</code>](#ISOSensitivity)  
**Read only**: true  
<a name="ISOSensitivity+sensitivity"></a>

## isoSensitivity.sensitivity : <code>number</code>
**Kind**: instance property of [<code>ISOSensitivity</code>](#ISOSensitivity)  
**Read only**: true  
<a name="ISOSensitivity+toJSON"></a>

## isoSensitivity.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>ISOSensitivity</code>](#ISOSensitivity)  
<a name="ISOSensitivity.ID"></a>

## ISOSensitivity.ID : <code>enum</code>
**Kind**: static enum of [<code>ISOSensitivity</code>](#ISOSensitivity)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Auto</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="ISOSensitivity.Values"></a>

## ISOSensitivity.Values : <code>enum</code>
**Kind**: static enum of [<code>ISOSensitivity</code>](#ISOSensitivity)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>40</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>48</td><td><code>number</code></td><td><code>12</code></td>
    </tr><tr>
    <td>56</td><td><code>number</code></td><td><code>25</code></td>
    </tr><tr>
    <td>64</td><td><code>number</code></td><td><code>50</code></td>
    </tr><tr>
    <td>72</td><td><code>number</code></td><td><code>100</code></td>
    </tr><tr>
    <td>75</td><td><code>number</code></td><td><code>125</code></td>
    </tr><tr>
    <td>77</td><td><code>number</code></td><td><code>160</code></td>
    </tr><tr>
    <td>80</td><td><code>number</code></td><td><code>200</code></td>
    </tr><tr>
    <td>83</td><td><code>number</code></td><td><code>250</code></td>
    </tr><tr>
    <td>85</td><td><code>number</code></td><td><code>320</code></td>
    </tr><tr>
    <td>88</td><td><code>number</code></td><td><code>400</code></td>
    </tr><tr>
    <td>91</td><td><code>number</code></td><td><code>500</code></td>
    </tr><tr>
    <td>93</td><td><code>number</code></td><td><code>640</code></td>
    </tr><tr>
    <td>96</td><td><code>number</code></td><td><code>800</code></td>
    </tr><tr>
    <td>99</td><td><code>number</code></td><td><code>1000</code></td>
    </tr><tr>
    <td>101</td><td><code>number</code></td><td><code>1250</code></td>
    </tr><tr>
    <td>104</td><td><code>number</code></td><td><code>1600</code></td>
    </tr><tr>
    <td>107</td><td><code>number</code></td><td><code>2000</code></td>
    </tr><tr>
    <td>109</td><td><code>number</code></td><td><code>2500</code></td>
    </tr><tr>
    <td>112</td><td><code>number</code></td><td><code>3200</code></td>
    </tr><tr>
    <td>115</td><td><code>number</code></td><td><code>4000</code></td>
    </tr><tr>
    <td>117</td><td><code>number</code></td><td><code>5000</code></td>
    </tr><tr>
    <td>120</td><td><code>number</code></td><td><code>6400</code></td>
    </tr><tr>
    <td>123</td><td><code>number</code></td><td><code>8000</code></td>
    </tr><tr>
    <td>125</td><td><code>number</code></td><td><code>10000</code></td>
    </tr><tr>
    <td>128</td><td><code>number</code></td><td><code>12800</code></td>
    </tr><tr>
    <td>131</td><td><code>number</code></td><td><code>16000</code></td>
    </tr><tr>
    <td>133</td><td><code>number</code></td><td><code>20000</code></td>
    </tr><tr>
    <td>136</td><td><code>number</code></td><td><code>25600</code></td>
    </tr><tr>
    <td>139</td><td><code>number</code></td><td><code>32000</code></td>
    </tr><tr>
    <td>141</td><td><code>number</code></td><td><code>40000</code></td>
    </tr><tr>
    <td>144</td><td><code>number</code></td><td><code>51200</code></td>
    </tr><tr>
    <td>147</td><td><code>number</code></td><td><code>64000</code></td>
    </tr><tr>
    <td>149</td><td><code>number</code></td><td><code>80000</code></td>
    </tr><tr>
    <td>152</td><td><code>number</code></td><td><code>102400</code></td>
    </tr><tr>
    <td>160</td><td><code>number</code></td><td><code>204800</code></td>
    </tr><tr>
    <td>168</td><td><code>number</code></td><td><code>409600</code></td>
    </tr><tr>
    <td>176</td><td><code>number</code></td><td><code>819200</code></td>
    </tr>  </tbody>
</table>

<a name="ISOSensitivity.forLabel"></a>

## ISOSensitivity.forLabel(label) ⇒ [<code>ISOSensitivity</code>](#ISOSensitivity) \| <code>null</code>
Create instance for label.

**Kind**: static method of [<code>ISOSensitivity</code>](#ISOSensitivity)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>label</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="LiveViewImage"></a>

# LiveViewImage
**Kind**: global class  

* [LiveViewImage](#LiveViewImage)
    * [new LiveViewImage()](#new_LiveViewImage_new)
    * [.coordinateSystem](#LiveViewImage+coordinateSystem) ⇒ <code>Size</code>
    * [.histogram](#LiveViewImage+histogram) ⇒ <code>Histogram</code>
    * [.histogramStatus](#LiveViewImage+histogramStatus) ⇒ [<code>Option</code>](#Option)
    * [.position](#LiveViewImage+position) ⇒ <code>Position</code>
    * [.visibleArea](#LiveViewImage+visibleArea) ⇒ <code>Rectangle</code>
    * [.zoom](#LiveViewImage+zoom) ⇒ [<code>Option</code>](#Option)
    * [.zoomPosition](#LiveViewImage+zoomPosition) ⇒ <code>Position</code>
    * [.zoomArea](#LiveViewImage+zoomArea) ⇒ <code>Rectangle</code>
    * [.getDataURL()](#LiveViewImage+getDataURL) ⇒ <code>string</code>

<a name="new_LiveViewImage_new"></a>

## new LiveViewImage()
Provided in [getLiveViewImage](#Camera+getLiveViewImage). Allows to download the file from camera.

<a name="LiveViewImage+coordinateSystem"></a>

## liveViewImage.coordinateSystem ⇒ <code>Size</code>
Coordinate system of the live view image

**Kind**: instance property of [<code>LiveViewImage</code>](#LiveViewImage)  
**Read only**: true  
<a name="LiveViewImage+histogram"></a>

## liveViewImage.histogram ⇒ <code>Histogram</code>
**Kind**: instance property of [<code>LiveViewImage</code>](#LiveViewImage)  
**Read only**: true  
<a name="LiveViewImage+histogramStatus"></a>

## liveViewImage.histogramStatus ⇒ [<code>Option</code>](#Option)
**Kind**: instance property of [<code>LiveViewImage</code>](#LiveViewImage)  
**Read only**: true  
<a name="LiveViewImage+position"></a>

## liveViewImage.position ⇒ <code>Position</code>
Cropping position of the enlarged live view image

**Kind**: instance property of [<code>LiveViewImage</code>](#LiveViewImage)  
**Read only**: true  
<a name="LiveViewImage+visibleArea"></a>

## liveViewImage.visibleArea ⇒ <code>Rectangle</code>
Visible area information according to Canon camera aspect settings

**Kind**: instance property of [<code>LiveViewImage</code>](#LiveViewImage)  
**Read only**: true  
<a name="LiveViewImage+zoom"></a>

## liveViewImage.zoom ⇒ [<code>Option</code>](#Option)
The zoom factor

**Kind**: instance property of [<code>LiveViewImage</code>](#LiveViewImage)  
**Read only**: true  
<a name="LiveViewImage+zoomPosition"></a>

## liveViewImage.zoomPosition ⇒ <code>Position</code>
The focus and zoom border position

**Kind**: instance property of [<code>LiveViewImage</code>](#LiveViewImage)  
**Read only**: true  
<a name="LiveViewImage+zoomArea"></a>

## liveViewImage.zoomArea ⇒ <code>Rectangle</code>
Focus and zoom border rectangle

**Kind**: instance property of [<code>LiveViewImage</code>](#LiveViewImage)  
**Read only**: true  
<a name="LiveViewImage+getDataURL"></a>

## liveViewImage.getDataURL() ⇒ <code>string</code>
Return as data url, the image will be base64 encoded.

**Kind**: instance method of [<code>LiveViewImage</code>](#LiveViewImage)  
**Returns**: <code>string</code> - data url  
<a name="ObjectEvent"></a>

# ObjectEvent ⇐ [<code>ApiIdentifier</code>](#ApiIdentifier)
**Kind**: global class  
**Extends**: [<code>ApiIdentifier</code>](#ApiIdentifier)  

* [ObjectEvent](#ObjectEvent) ⇐ [<code>ApiIdentifier</code>](#ApiIdentifier)
    * [new ObjectEvent(identifier)](#new_ObjectEvent_new)
    * _instance_
        * [.label](#ApiIdentifier+label) : <code>string</code>
        * [.identifier](#ApiIdentifier+identifier) : <code>number</code>
        * [.equalTo(other)](#ObjectEvent+equalTo) ⇒ <code>boolean</code>
        * [.Symbol_toPrimitive(hint)](#ApiIdentifier+Symbol_toPrimitive) ⇒ <code>string</code> \| <code>number</code> \| <code>null</code>
        * [.toJSON()](#ApiIdentifier+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.ID](#ObjectEvent.ID) : <code>enum</code>

<a name="new_ObjectEvent_new"></a>

## new ObjectEvent(identifier)
Encapsulate Object Event Identifiers For Easy Read And Debug

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>identifier</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+label"></a>

## objectEvent.label : <code>string</code>
**Kind**: instance property of [<code>ObjectEvent</code>](#ObjectEvent)  
**Read only**: true  
<a name="ApiIdentifier+identifier"></a>

## objectEvent.identifier : <code>number</code>
**Kind**: instance property of [<code>ObjectEvent</code>](#ObjectEvent)  
**Read only**: true  
<a name="ObjectEvent+equalTo"></a>

## objectEvent.equalTo(other) ⇒ <code>boolean</code>
**Kind**: instance method of [<code>ObjectEvent</code>](#ObjectEvent)  
**Overrides**: [<code>equalTo</code>](#ApiIdentifier+equalTo)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Description</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>other</td><td><code>number</code> | <code><a href="#ObjectEvent">ObjectEvent</a></code></td><td><p>The other value</p>
</td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+Symbol_toPrimitive"></a>

## objectEvent.Symbol\_toPrimitive(hint) ⇒ <code>string</code> \| <code>number</code> \| <code>null</code>
Allows type cast to number and string.The string will be a hexadecimal code representation of the number

**Kind**: instance method of [<code>ObjectEvent</code>](#ObjectEvent)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>hint</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+toJSON"></a>

## objectEvent.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>ObjectEvent</code>](#ObjectEvent)  
<a name="ObjectEvent.ID"></a>

## ObjectEvent.ID : <code>enum</code>
**Kind**: static enum of [<code>ObjectEvent</code>](#ObjectEvent)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>All</td><td><code>number</code></td><td><code>512</code></td>
    </tr><tr>
    <td>DirItemCancelTransferDT</td><td><code>number</code></td><td><code>522</code></td>
    </tr><tr>
    <td>DirItemContentChanged</td><td><code>number</code></td><td><code>519</code></td>
    </tr><tr>
    <td>DirItemCreated</td><td><code>number</code></td><td><code>516</code></td>
    </tr><tr>
    <td>DirItemInfoChanged</td><td><code>number</code></td><td><code>518</code></td>
    </tr><tr>
    <td>DirItemRemoved</td><td><code>number</code></td><td><code>517</code></td>
    </tr><tr>
    <td>DirItemRequestTransfer</td><td><code>number</code></td><td><code>520</code></td>
    </tr><tr>
    <td>DirItemRequestTransferDT</td><td><code>number</code></td><td><code>521</code></td>
    </tr><tr>
    <td>FolderUpdateItems</td><td><code>number</code></td><td><code>515</code></td>
    </tr><tr>
    <td>VolumeAdded</td><td><code>number</code></td><td><code>524</code></td>
    </tr><tr>
    <td>VolumeInfoChanged</td><td><code>number</code></td><td><code>513</code></td>
    </tr><tr>
    <td>VolumeRemoved</td><td><code>number</code></td><td><code>525</code></td>
    </tr><tr>
    <td>VolumeUpdateItems</td><td><code>number</code></td><td><code>514</code></td>
    </tr>  </tbody>
</table>

<a name="Option"></a>

# Option
**Kind**: global class  

* [Option](#Option)
    * [new Option(propertyID_, value_)](#new_Option_new)
    * _instance_
        * [.label](#Option+label) : <code>string</code>
        * [.value](#Option+value) : <code>number</code>
        * [.propertyID](#Option+propertyID) : <code>number</code>
    * _static_
        * [.AEMode](#Option.AEMode) : <code>enum</code>
        * [.AEModeSelect](#Option.AEModeSelect) : <code>enum</code>
        * [.AFMode](#Option.AFMode) : <code>enum</code>
        * [.BatteryQuality](#Option.BatteryQuality) : <code>enum</code>
        * [.Bracket](#Option.Bracket) : <code>enum</code>
        * [.ColorSpace](#Option.ColorSpace) : <code>enum</code>
        * [.DCStrobe](#Option.DCStrobe) : <code>enum</code>
        * [.DriveMode](#Option.DriveMode) : <code>enum</code>
        * [.EvfAFMode](#Option.EvfAFMode) : <code>enum</code>
        * [.EvfHistogramStatus](#Option.EvfHistogramStatus) : <code>enum</code>
        * [.EvfOutputDevice](#Option.EvfOutputDevice) : <code>enum</code>
        * [.EvfZoom](#Option.EvfZoom) : <code>enum</code>
        * [.LensBarrelStatus](#Option.LensBarrelStatus) : <code>enum</code>
        * [.LensStatus](#Option.LensStatus) : <code>enum</code>
        * [.MeteringMode](#Option.MeteringMode) : <code>enum</code>
        * [.MirrorUpStatus](#Option.MirrorUpStatus) : <code>enum</code>
        * [.MovieQuality](#Option.MovieQuality) : <code>enum</code>
        * [.NoiseReduction](#Option.NoiseReduction) : <code>enum</code>
        * [.RedEye](#Option.RedEye) : <code>enum</code>
        * [.Record](#Option.Record) : <code>enum</code>
        * [.SaveTo](#Option.SaveTo) : <code>enum</code>
        * [.WhiteBalance](#Option.WhiteBalance) : <code>enum</code>
        * [.forLabel(label)](#Option.forLabel) ⇒ [<code>Option</code>](#Option) \| <code>null</code>

<a name="new_Option_new"></a>

## new Option(propertyID_, value_)
Option represents a property value from a property specific list.It provides constants for all possible property values. However it dependson the camera and the camera status which option values are available.

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>propertyID_</td><td><code>number</code></td>
    </tr><tr>
    <td>value_</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="Option+label"></a>

## option.label : <code>string</code>
**Kind**: instance property of [<code>Option</code>](#Option)  
**Read only**: true  
<a name="Option+value"></a>

## option.value : <code>number</code>
**Kind**: instance property of [<code>Option</code>](#Option)  
**Read only**: true  
<a name="Option+propertyID"></a>

## option.propertyID : <code>number</code>
**Kind**: instance property of [<code>Option</code>](#Option)  
**Read only**: true  
<a name="Option.AEMode"></a>

## Option.AEMode : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>A_DEP</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>Av</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>BackgroundBlur</td><td><code>number</code></td><td><code>62</code></td>
    </tr><tr>
    <td>BacklitScenes</td><td><code>number</code></td><td><code>24</code></td>
    </tr><tr>
    <td>Bulb</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>CandlelightPortraits</td><td><code>number</code></td><td><code>28</code></td>
    </tr><tr>
    <td>Children</td><td><code>number</code></td><td><code>26</code></td>
    </tr><tr>
    <td>Closeup</td><td><code>number</code></td><td><code>14</code></td>
    </tr><tr>
    <td>CreativeAuto</td><td><code>number</code></td><td><code>19</code></td>
    </tr><tr>
    <td>CreativeFilter</td><td><code>number</code></td><td><code>29</code></td>
    </tr><tr>
    <td>Custom</td><td><code>number</code></td><td><code>7</code></td>
    </tr><tr>
    <td>DEP</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>Fireworks</td><td><code>number</code></td><td><code>57</code></td>
    </tr><tr>
    <td>Fisheye</td><td><code>number</code></td><td><code>33</code></td>
    </tr><tr>
    <td>FlashOff</td><td><code>number</code></td><td><code>15</code></td>
    </tr><tr>
    <td>Flexible</td><td><code>number</code></td><td><code>55</code></td>
    </tr><tr>
    <td>Food</td><td><code>number</code></td><td><code>27</code></td>
    </tr><tr>
    <td>Green</td><td><code>number</code></td><td><code>9</code></td>
    </tr><tr>
    <td>GroupPhoto</td><td><code>number</code></td><td><code>46</code></td>
    </tr><tr>
    <td>Hdr_Bold</td><td><code>number</code></td><td><code>38</code></td>
    </tr><tr>
    <td>Hdr_Embossed</td><td><code>number</code></td><td><code>39</code></td>
    </tr><tr>
    <td>Hdr_Standard</td><td><code>number</code></td><td><code>36</code></td>
    </tr><tr>
    <td>Hdr_Vivid</td><td><code>number</code></td><td><code>37</code></td>
    </tr><tr>
    <td>Landscape</td><td><code>number</code></td><td><code>13</code></td>
    </tr><tr>
    <td>Lock</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>Manual</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>Miniature</td><td><code>number</code></td><td><code>35</code></td>
    </tr><tr>
    <td>Movie</td><td><code>number</code></td><td><code>20</code></td>
    </tr><tr>
    <td>Movie_DirectMono</td><td><code>number</code></td><td><code>43</code></td>
    </tr><tr>
    <td>Movie_Fantasy</td><td><code>number</code></td><td><code>40</code></td>
    </tr><tr>
    <td>Movie_Memory</td><td><code>number</code></td><td><code>42</code></td>
    </tr><tr>
    <td>Movie_Mini</td><td><code>number</code></td><td><code>44</code></td>
    </tr><tr>
    <td>Movie_Old</td><td><code>number</code></td><td><code>41</code></td>
    </tr><tr>
    <td>Myself</td><td><code>number</code></td><td><code>50</code></td>
    </tr><tr>
    <td>NightPortrait</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>NightScenes</td><td><code>number</code></td><td><code>23</code></td>
    </tr><tr>
    <td>OilPainting</td><td><code>number</code></td><td><code>56</code></td>
    </tr><tr>
    <td>PanningAssist</td><td><code>number</code></td><td><code>45</code></td>
    </tr><tr>
    <td>Panorama</td><td><code>number</code></td><td><code>53</code></td>
    </tr><tr>
    <td>PhotoInMovie</td><td><code>number</code></td><td><code>21</code></td>
    </tr><tr>
    <td>PlusMovieAuto</td><td><code>number</code></td><td><code>51</code></td>
    </tr><tr>
    <td>Portrait</td><td><code>number</code></td><td><code>12</code></td>
    </tr><tr>
    <td>ProgramAE</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>RoughMonoChrome</td><td><code>number</code></td><td><code>30</code></td>
    </tr><tr>
    <td>SCN</td><td><code>number</code></td><td><code>25</code></td>
    </tr><tr>
    <td>SceneIntelligentAuto</td><td><code>number</code></td><td><code>22</code></td>
    </tr><tr>
    <td>Silent</td><td><code>number</code></td><td><code>54</code></td>
    </tr><tr>
    <td>SmoothSkin</td><td><code>number</code></td><td><code>52</code></td>
    </tr><tr>
    <td>SoftFocus</td><td><code>number</code></td><td><code>31</code></td>
    </tr><tr>
    <td>Sports</td><td><code>number</code></td><td><code>11</code></td>
    </tr><tr>
    <td>StarNightScape</td><td><code>number</code></td><td><code>59</code></td>
    </tr><tr>
    <td>StarPortrait</td><td><code>number</code></td><td><code>58</code></td>
    </tr><tr>
    <td>StarTimelapseMovie</td><td><code>number</code></td><td><code>61</code></td>
    </tr><tr>
    <td>StarTrails</td><td><code>number</code></td><td><code>60</code></td>
    </tr><tr>
    <td>ToyCamera</td><td><code>number</code></td><td><code>32</code></td>
    </tr><tr>
    <td>Tv</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>Unknown</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr><tr>
    <td>VideoBlog</td><td><code>number</code></td><td><code>63</code></td>
    </tr><tr>
    <td>WaterColor</td><td><code>number</code></td><td><code>34</code></td>
    </tr>  </tbody>
</table>

<a name="Option.AEModeSelect"></a>

## Option.AEModeSelect : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>A_DEP</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>Av</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>BackgroundBlur</td><td><code>number</code></td><td><code>62</code></td>
    </tr><tr>
    <td>BacklitScenes</td><td><code>number</code></td><td><code>24</code></td>
    </tr><tr>
    <td>Bulb</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>CandlelightPortraits</td><td><code>number</code></td><td><code>28</code></td>
    </tr><tr>
    <td>Children</td><td><code>number</code></td><td><code>26</code></td>
    </tr><tr>
    <td>Closeup</td><td><code>number</code></td><td><code>14</code></td>
    </tr><tr>
    <td>CreativeAuto</td><td><code>number</code></td><td><code>19</code></td>
    </tr><tr>
    <td>CreativeFilter</td><td><code>number</code></td><td><code>29</code></td>
    </tr><tr>
    <td>Custom</td><td><code>number</code></td><td><code>7</code></td>
    </tr><tr>
    <td>Custom2</td><td><code>number</code></td><td><code>16</code></td>
    </tr><tr>
    <td>Custom3</td><td><code>number</code></td><td><code>17</code></td>
    </tr><tr>
    <td>DEP</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>Fireworks</td><td><code>number</code></td><td><code>57</code></td>
    </tr><tr>
    <td>Fisheye</td><td><code>number</code></td><td><code>33</code></td>
    </tr><tr>
    <td>FlashOff</td><td><code>number</code></td><td><code>15</code></td>
    </tr><tr>
    <td>Flexible</td><td><code>number</code></td><td><code>55</code></td>
    </tr><tr>
    <td>Food</td><td><code>number</code></td><td><code>27</code></td>
    </tr><tr>
    <td>Green</td><td><code>number</code></td><td><code>9</code></td>
    </tr><tr>
    <td>GroupPhoto</td><td><code>number</code></td><td><code>46</code></td>
    </tr><tr>
    <td>Hdr_Bold</td><td><code>number</code></td><td><code>38</code></td>
    </tr><tr>
    <td>Hdr_Embossed</td><td><code>number</code></td><td><code>39</code></td>
    </tr><tr>
    <td>Hdr_Standard</td><td><code>number</code></td><td><code>36</code></td>
    </tr><tr>
    <td>Hdr_Vivid</td><td><code>number</code></td><td><code>37</code></td>
    </tr><tr>
    <td>Landscape</td><td><code>number</code></td><td><code>13</code></td>
    </tr><tr>
    <td>Lock</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>Manual</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>Miniature</td><td><code>number</code></td><td><code>35</code></td>
    </tr><tr>
    <td>Movie</td><td><code>number</code></td><td><code>20</code></td>
    </tr><tr>
    <td>Movie_DirectMono</td><td><code>number</code></td><td><code>43</code></td>
    </tr><tr>
    <td>Movie_Fantasy</td><td><code>number</code></td><td><code>40</code></td>
    </tr><tr>
    <td>Movie_Memory</td><td><code>number</code></td><td><code>42</code></td>
    </tr><tr>
    <td>Movie_Mini</td><td><code>number</code></td><td><code>44</code></td>
    </tr><tr>
    <td>Movie_Old</td><td><code>number</code></td><td><code>41</code></td>
    </tr><tr>
    <td>Myself</td><td><code>number</code></td><td><code>50</code></td>
    </tr><tr>
    <td>NightPortrait</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>NightScenes</td><td><code>number</code></td><td><code>23</code></td>
    </tr><tr>
    <td>OilPainting</td><td><code>number</code></td><td><code>56</code></td>
    </tr><tr>
    <td>PanningAssist</td><td><code>number</code></td><td><code>45</code></td>
    </tr><tr>
    <td>Panorama</td><td><code>number</code></td><td><code>53</code></td>
    </tr><tr>
    <td>PhotoInMovie</td><td><code>number</code></td><td><code>21</code></td>
    </tr><tr>
    <td>PlusMovieAuto</td><td><code>number</code></td><td><code>51</code></td>
    </tr><tr>
    <td>Portrait</td><td><code>number</code></td><td><code>12</code></td>
    </tr><tr>
    <td>ProgramAE</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>RoughMonoChrome</td><td><code>number</code></td><td><code>30</code></td>
    </tr><tr>
    <td>SCN</td><td><code>number</code></td><td><code>25</code></td>
    </tr><tr>
    <td>SceneIntelligentAuto</td><td><code>number</code></td><td><code>22</code></td>
    </tr><tr>
    <td>Silent</td><td><code>number</code></td><td><code>54</code></td>
    </tr><tr>
    <td>SmoothSkin</td><td><code>number</code></td><td><code>52</code></td>
    </tr><tr>
    <td>SoftFocus</td><td><code>number</code></td><td><code>31</code></td>
    </tr><tr>
    <td>Sports</td><td><code>number</code></td><td><code>11</code></td>
    </tr><tr>
    <td>StarNightScape</td><td><code>number</code></td><td><code>59</code></td>
    </tr><tr>
    <td>StarPortrait</td><td><code>number</code></td><td><code>58</code></td>
    </tr><tr>
    <td>StarTimelapseMovie</td><td><code>number</code></td><td><code>61</code></td>
    </tr><tr>
    <td>StarTrails</td><td><code>number</code></td><td><code>60</code></td>
    </tr><tr>
    <td>ToyCamera</td><td><code>number</code></td><td><code>32</code></td>
    </tr><tr>
    <td>Tv</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>Unknown</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr><tr>
    <td>WaterColor</td><td><code>number</code></td><td><code>34</code></td>
    </tr>  </tbody>
</table>

<a name="Option.AFMode"></a>

## Option.AFMode : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>AIFocus</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>AIServo</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>ManualFocus</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>NotValid</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr><tr>
    <td>OneShot</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Option.BatteryQuality"></a>

## Option.BatteryQuality : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Full</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>Half</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>High</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>Low</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Option.Bracket"></a>

## Option.Bracket : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>AEBracket</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>BracketOff</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr><tr>
    <td>FEBracket</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>ISOBracket</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>WBBracket</td><td><code>number</code></td><td><code>4</code></td>
    </tr>  </tbody>
</table>

<a name="Option.ColorSpace"></a>

## Option.ColorSpace : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>AdobeRGB</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>Unknown</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr><tr>
    <td>sRGB</td><td><code>number</code></td><td><code>1</code></td>
    </tr>  </tbody>
</table>

<a name="Option.DCStrobe"></a>

## Option.DCStrobe : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Auto</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>Off</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>On</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>SlowSynchro</td><td><code>number</code></td><td><code>2</code></td>
    </tr>  </tbody>
</table>

<a name="Option.DriveMode"></a>

## Option.DriveMode : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>ContinuousShooting</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>HighSpeedContinuous</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>LowSpeedContinuous</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>SelfTimer10sec</td><td><code>number</code></td><td><code>16</code></td>
    </tr><tr>
    <td>SelfTimer2sec</td><td><code>number</code></td><td><code>17</code></td>
    </tr><tr>
    <td>SelfTimerContinuous</td><td><code>number</code></td><td><code>7</code></td>
    </tr><tr>
    <td>SilentContinuousShooting</td><td><code>number</code></td><td><code>20</code></td>
    </tr><tr>
    <td>SilentHSContinuous</td><td><code>number</code></td><td><code>21</code></td>
    </tr><tr>
    <td>SilentLSContinuous</td><td><code>number</code></td><td><code>22</code></td>
    </tr><tr>
    <td>SilentSingleShooting</td><td><code>number</code></td><td><code>19</code></td>
    </tr><tr>
    <td>SingleShooting</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>SingleSilentShooting</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>SuperHighSpeed14fps</td><td><code>number</code></td><td><code>18</code></td>
    </tr><tr>
    <td>Video</td><td><code>number</code></td><td><code>2</code></td>
    </tr>  </tbody>
</table>

<a name="Option.EvfAFMode"></a>

## Option.EvfAFMode : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>ExpandAFAreaAround</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>ExpandAFAreaCross</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>FaceTracking</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>FlexiZoneMulti</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>LargeZoneAFHorizontal</td><td><code>number</code></td><td><code>7</code></td>
    </tr><tr>
    <td>LargeZoneAFVertical</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>OnePointAF</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>Quick</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>SpotAF</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>TrackingAF</td><td><code>number</code></td><td><code>9</code></td>
    </tr><tr>
    <td>ZoneAF</td><td><code>number</code></td><td><code>4</code></td>
    </tr>  </tbody>
</table>

<a name="Option.EvfHistogramStatus"></a>

## Option.EvfHistogramStatus : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Grayout</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>Hide</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>Normal</td><td><code>number</code></td><td><code>1</code></td>
    </tr>  </tbody>
</table>

<a name="Option.EvfOutputDevice"></a>

## Option.EvfOutputDevice : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>None</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>PC</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>SmallPC</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>TFT</td><td><code>number</code></td><td><code>1</code></td>
    </tr>  </tbody>
</table>

<a name="Option.EvfZoom"></a>

## Option.EvfZoom : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Fit</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>x10</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>x5</td><td><code>number</code></td><td><code>5</code></td>
    </tr>  </tbody>
</table>

<a name="Option.LensBarrelStatus"></a>

## Option.LensBarrelStatus : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Inner</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>Outer</td><td><code>number</code></td><td><code>1</code></td>
    </tr>  </tbody>
</table>

<a name="Option.LensStatus"></a>

## Option.LensStatus : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Attached</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>NotAttached</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Option.MeteringMode"></a>

## Option.MeteringMode : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>CenterWeightedAverage</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>Evaluative</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>NotValid</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr><tr>
    <td>Partial</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>Spot</td><td><code>number</code></td><td><code>1</code></td>
    </tr>  </tbody>
</table>

<a name="Option.MirrorUpStatus"></a>

## Option.MirrorUpStatus : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Disable</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>DuringShooting</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>Enable</td><td><code>number</code></td><td><code>1</code></td>
    </tr>  </tbody>
</table>

<a name="Option.MovieQuality"></a>

## Option.MovieQuality : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>"1280x720 100.0fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>71696</code></td>
    </tr><tr>
    <td>"1280x720 100.0fps Standard(IPB)"</td><td><code>number</code></td><td><code>71728</code></td>
    </tr><tr>
    <td>"1280x720 119.9fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>71952</code></td>
    </tr><tr>
    <td>"1280x720 119.9fps Standard(IPB)"</td><td><code>number</code></td><td><code>71984</code></td>
    </tr><tr>
    <td>"1280x720 25.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>70704</code></td>
    </tr><tr>
    <td>"1280x720 29.97fps Light(IPB)"</td><td><code>number</code></td><td><code>70961</code></td>
    </tr><tr>
    <td>"1280x720 29.97fps Standard(IPB)"</td><td><code>number</code></td><td><code>70960</code></td>
    </tr><tr>
    <td>"1280x720 50.00fps"</td><td><code>number</code></td><td><code>67072</code></td>
    </tr><tr>
    <td>"1280x720 50.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>71184</code></td>
    </tr><tr>
    <td>"1280x720 50.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>71216</code></td>
    </tr><tr>
    <td>"1280x720 59.94fps"</td><td><code>number</code></td><td><code>67328</code></td>
    </tr><tr>
    <td>"1280x720 59.94fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>71440</code></td>
    </tr><tr>
    <td>"1280x720 59.94fps Standard(IPB)"</td><td><code>number</code></td><td><code>71472</code></td>
    </tr><tr>
    <td>"1920x1080 100.0fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>6160</code></td>
    </tr><tr>
    <td>"1920x1080 119.9fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>6416</code></td>
    </tr><tr>
    <td>"1920x1080 23.98fps"</td><td><code>number</code></td><td><code>512</code></td>
    </tr><tr>
    <td>"1920x1080 23.98fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>4624</code></td>
    </tr><tr>
    <td>"1920x1080 23.98fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134222352</code></td>
    </tr><tr>
    <td>"1920x1080 23.98fps Standard(IPB)"</td><td><code>number</code></td><td><code>4656</code></td>
    </tr><tr>
    <td>"1920x1080 23.98fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134222384</code></td>
    </tr><tr>
    <td>"1920x1080 24.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>4880</code></td>
    </tr><tr>
    <td>"1920x1080 24.00fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134222864</code></td>
    </tr><tr>
    <td>"1920x1080 24.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>4912</code></td>
    </tr><tr>
    <td>"1920x1080 24.00fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134222896</code></td>
    </tr><tr>
    <td>"1920x1080 25.00fps"</td><td><code>number</code></td><td><code>1024</code></td>
    </tr><tr>
    <td>"1920x1080 25.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>5136</code></td>
    </tr><tr>
    <td>"1920x1080 25.00fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134222897</code></td>
    </tr><tr>
    <td>"1920x1080 25.00fps Light(IPB)"</td><td><code>number</code></td><td><code>5169</code></td>
    </tr><tr>
    <td>"1920x1080 25.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>5168</code></td>
    </tr><tr>
    <td>"1920x1080 25.00fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134223120</code></td>
    </tr><tr>
    <td>"1920x1080 29.94fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134223153</code></td>
    </tr><tr>
    <td>"1920x1080 29.97fps"</td><td><code>number</code></td><td><code>1280</code></td>
    </tr><tr>
    <td>"1920x1080 29.97fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>1296</code></td>
    </tr><tr>
    <td>"1920x1080 29.97fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134223152</code></td>
    </tr><tr>
    <td>"1920x1080 29.97fps Light(IPB)"</td><td><code>number</code></td><td><code>5425</code></td>
    </tr><tr>
    <td>"1920x1080 29.97fps Standard(IPB)"</td><td><code>number</code></td><td><code>5424</code></td>
    </tr><tr>
    <td>"1920x1080 50.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>5648</code></td>
    </tr><tr>
    <td>"1920x1080 50.00fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134223376</code></td>
    </tr><tr>
    <td>"1920x1080 50.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>5680</code></td>
    </tr><tr>
    <td>"1920x1080 50.00fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134223408</code></td>
    </tr><tr>
    <td>"1920x1080 59.94fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>5904</code></td>
    </tr><tr>
    <td>"1920x1080 59.94fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134223632</code></td>
    </tr><tr>
    <td>"1920x1080 59.94fps Standard(IPB)"</td><td><code>number</code></td><td><code>5936</code></td>
    </tr><tr>
    <td>"1920x1080 59.94fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134223664</code></td>
    </tr><tr>
    <td>"23.98fps (RAW)"</td><td><code>number</code></td><td><code>668272</code></td>
    </tr><tr>
    <td>"24.00fps (RAW)"</td><td><code>number</code></td><td><code>668528</code></td>
    </tr><tr>
    <td>"25.00fps (RAW)"</td><td><code>number</code></td><td><code>668784</code></td>
    </tr><tr>
    <td>"29.97fps (RAW)"</td><td><code>number</code></td><td><code>669040</code></td>
    </tr><tr>
    <td>"3840x2160 100.0fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>333840</code></td>
    </tr><tr>
    <td>"3840x2160 119.9fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>334096</code></td>
    </tr><tr>
    <td>"3840x2160 23.98fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>134550032</code></td>
    </tr><tr>
    <td>"3840x2160 23.98fps Standard(IPB)"</td><td><code>number</code></td><td><code>134550064</code></td>
    </tr><tr>
    <td>"3840x2160 24.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>332560</code></td>
    </tr><tr>
    <td>"3840x2160 24.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>332592</code></td>
    </tr><tr>
    <td>"3840x2160 25.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>134550544</code></td>
    </tr><tr>
    <td>"3840x2160 25.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>134550576</code></td>
    </tr><tr>
    <td>"3840x2160 29.97fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>134550800</code></td>
    </tr><tr>
    <td>"3840x2160 29.97fps Standard(IPB)"</td><td><code>number</code></td><td><code>134550832</code></td>
    </tr><tr>
    <td>"3840x2160 50.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>134551056</code></td>
    </tr><tr>
    <td>"3840x2160 50.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>134551088</code></td>
    </tr><tr>
    <td>"3840x2160 59.94fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>134551312</code></td>
    </tr><tr>
    <td>"3840x2160 59.94fps Standard(IPB)"</td><td><code>number</code></td><td><code>134551344</code></td>
    </tr><tr>
    <td>"4096x2160 100.0fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>202768</code></td>
    </tr><tr>
    <td>"4096x2160 119.9fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>203024</code></td>
    </tr><tr>
    <td>"4096x2160 23.98fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>201232</code></td>
    </tr><tr>
    <td>"4096x2160 23.98fps For editing(ALL-I) Crop"</td><td><code>number</code></td><td><code>134418960</code></td>
    </tr><tr>
    <td>"4096x2160 23.98fps Motion JPEG"</td><td><code>number</code></td><td><code>197184</code></td>
    </tr><tr>
    <td>"4096x2160 23.98fps Standard(IPB)"</td><td><code>number</code></td><td><code>201264</code></td>
    </tr><tr>
    <td>"4096x2160 23.98fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134418992</code></td>
    </tr><tr>
    <td>"4096x2160 24.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>201488</code></td>
    </tr><tr>
    <td>"4096x2160 24.00fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134419216</code></td>
    </tr><tr>
    <td>"4096x2160 24.00fps Motion JPEG"</td><td><code>number</code></td><td><code>197440</code></td>
    </tr><tr>
    <td>"4096x2160 24.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>201520</code></td>
    </tr><tr>
    <td>"4096x2160 24.00fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134419248</code></td>
    </tr><tr>
    <td>"4096x2160 25.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>201744</code></td>
    </tr><tr>
    <td>"4096x2160 25.00fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134419472</code></td>
    </tr><tr>
    <td>"4096x2160 25.00fps Motion JPEG"</td><td><code>number</code></td><td><code>197696</code></td>
    </tr><tr>
    <td>"4096x2160 25.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>201776</code></td>
    </tr><tr>
    <td>"4096x2160 25.00fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134419504</code></td>
    </tr><tr>
    <td>"4096x2160 29.94fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134419760</code></td>
    </tr><tr>
    <td>"4096x2160 29.970fps Standard(IPB)"</td><td><code>number</code></td><td><code>202032</code></td>
    </tr><tr>
    <td>"4096x2160 29.97fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>202000</code></td>
    </tr><tr>
    <td>"4096x2160 29.97fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134419728</code></td>
    </tr><tr>
    <td>"4096x2160 29.97fps Motion JPEG"</td><td><code>number</code></td><td><code>197952</code></td>
    </tr><tr>
    <td>"4096x2160 50.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>202256</code></td>
    </tr><tr>
    <td>"4096x2160 50.00fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134419984</code></td>
    </tr><tr>
    <td>"4096x2160 50.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>202288</code></td>
    </tr><tr>
    <td>"4096x2160 50.00fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134420016</code></td>
    </tr><tr>
    <td>"4096x2160 59.94fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>202512</code></td>
    </tr><tr>
    <td>"4096x2160 59.94fps For editing(ALL-I)Crop"</td><td><code>number</code></td><td><code>134420240</code></td>
    </tr><tr>
    <td>"4096x2160 59.94fps Standard(IPB)"</td><td><code>number</code></td><td><code>202544</code></td>
    </tr><tr>
    <td>"4096x2160 59.94fps Standard(IPB)Crop"</td><td><code>number</code></td><td><code>134420272</code></td>
    </tr><tr>
    <td>"50.00fps (RAW)"</td><td><code>number</code></td><td><code>669296</code></td>
    </tr><tr>
    <td>"59.94fps (RAW)"</td><td><code>number</code></td><td><code>669552</code></td>
    </tr><tr>
    <td>"640x480 25.00fps"</td><td><code>number</code></td><td><code>132096</code></td>
    </tr><tr>
    <td>"640x480 29.97ffps"</td><td><code>number</code></td><td><code>132352</code></td>
    </tr><tr>
    <td>"7680x4320 23.98fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>594448</code></td>
    </tr><tr>
    <td>"7680x4320 23.98fps Standard(IPB)"</td><td><code>number</code></td><td><code>594480</code></td>
    </tr><tr>
    <td>"7680x4320 25.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>594960</code></td>
    </tr><tr>
    <td>"7680x4320 25.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>594992</code></td>
    </tr><tr>
    <td>"7680x4320 29.97fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>595216</code></td>
    </tr><tr>
    <td>"7680x4320 29.97fps Standard(IPB)"</td><td><code>number</code></td><td><code>595248</code></td>
    </tr><tr>
    <td>"8192x4320 23.98fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>528912</code></td>
    </tr><tr>
    <td>"8192x4320 23.98fps Standard(IPB)"</td><td><code>number</code></td><td><code>528944</code></td>
    </tr><tr>
    <td>"8192x4320 24.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>529168</code></td>
    </tr><tr>
    <td>"8192x4320 24.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>529200</code></td>
    </tr><tr>
    <td>"8192x4320 25.00fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>529424</code></td>
    </tr><tr>
    <td>"8192x4320 25.00fps Standard(IPB)"</td><td><code>number</code></td><td><code>529456</code></td>
    </tr><tr>
    <td>"8192x4320 29.97fps For editing(ALL-I)"</td><td><code>number</code></td><td><code>529680</code></td>
    </tr><tr>
    <td>"8192x4320 29.97fps Standard(IPB)"</td><td><code>number</code></td><td><code>529712</code></td>
    </tr>  </tbody>
</table>

<a name="Option.NoiseReduction"></a>

## Option.NoiseReduction : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Auto</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>Off</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>On1</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>On2</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>On3</td><td><code>number</code></td><td><code>3</code></td>
    </tr>  </tbody>
</table>

<a name="Option.RedEye"></a>

## Option.RedEye : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Invalid</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr><tr>
    <td>Off</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>On</td><td><code>number</code></td><td><code>1</code></td>
    </tr>  </tbody>
</table>

<a name="Option.Record"></a>

## Option.Record : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Begin</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>End</td><td><code>number</code></td><td><code>0</code></td>
    </tr>  </tbody>
</table>

<a name="Option.SaveTo"></a>

## Option.SaveTo : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Both</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>Camera</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>Host</td><td><code>number</code></td><td><code>2</code></td>
    </tr>  </tbody>
</table>

<a name="Option.WhiteBalance"></a>

## Option.WhiteBalance : <code>enum</code>
**Kind**: static enum of [<code>Option</code>](#Option)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>AutoAmbiencePriority</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>AutoWhitePriority</td><td><code>number</code></td><td><code>23</code></td>
    </tr><tr>
    <td>Click</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr><tr>
    <td>Cloudy</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>ColorTemperature</td><td><code>number</code></td><td><code>9</code></td>
    </tr><tr>
    <td>CustomPC1</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>CustomPC2</td><td><code>number</code></td><td><code>11</code></td>
    </tr><tr>
    <td>CustomPC3</td><td><code>number</code></td><td><code>12</code></td>
    </tr><tr>
    <td>CustomPC4</td><td><code>number</code></td><td><code>20</code></td>
    </tr><tr>
    <td>CustomPC5</td><td><code>number</code></td><td><code>21</code></td>
    </tr><tr>
    <td>Daylight</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>Flash</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>Fluorescent</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>Pasted</td><td><code>number</code></td><td><code>4294967294</code></td>
    </tr><tr>
    <td>Shade</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>Tungsten</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>WhitePaper</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>WhitePaper2</td><td><code>number</code></td><td><code>15</code></td>
    </tr><tr>
    <td>WhitePaper3</td><td><code>number</code></td><td><code>16</code></td>
    </tr><tr>
    <td>WhitePaper4</td><td><code>number</code></td><td><code>18</code></td>
    </tr><tr>
    <td>WhitePaper5</td><td><code>number</code></td><td><code>19</code></td>
    </tr>  </tbody>
</table>

<a name="Option.forLabel"></a>

## Option.forLabel(label) ⇒ [<code>Option</code>](#Option) \| <code>null</code>
Create instance for label.

**Kind**: static method of [<code>Option</code>](#Option)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>label</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="Flag"></a>

# Flag
**Kind**: global class  

* [Flag](#Flag)
    * [new Flag(value)](#new_Flag_new)
    * [new Flag(value)](#new_Flag_new)
    * _instance_
        * [.label](#Flag+label) : <code>string</code>
        * [.value](#Flag+value) : <code>number</code>
        * [.flag](#Flag+flag) : <code>boolean</code>
        * [.toJSON()](#Flag+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.True](#Flag.True) : <code>number</code>
        * [.False](#Flag.False) : <code>number</code>
        * [.forLabel(label)](#Flag.forLabel) ⇒ [<code>Flag</code>](#Flag)

<a name="new_Flag_new"></a>

## new Flag(value)
Boolean property value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value</td><td><code>number</code> | <code>boolean</code></td>
    </tr>  </tbody>
</table>

<a name="new_Flag_new"></a>

## new Flag(value)
Boolean property value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value</td><td><code>number</code> | <code>boolean</code></td>
    </tr>  </tbody>
</table>

<a name="Flag+label"></a>

## flag.label : <code>string</code>
**Kind**: instance property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag+value"></a>

## flag.value : <code>number</code>
**Kind**: instance property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag+flag"></a>

## flag.flag : <code>boolean</code>
**Kind**: instance property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag+toJSON"></a>

## flag.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>Flag</code>](#Flag)  
<a name="Flag.True"></a>

## Flag.True : <code>number</code>
**Kind**: static property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag.False"></a>

## Flag.False : <code>number</code>
**Kind**: static property of [<code>Flag</code>](#Flag)  
**Read only**: true  
<a name="Flag.forLabel"></a>

## Flag.forLabel(label) ⇒ [<code>Flag</code>](#Flag)
Create instance for label.

**Kind**: static method of [<code>Flag</code>](#Flag)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>label</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="ShutterSpeed"></a>

# ShutterSpeed
**Kind**: global class  

* [ShutterSpeed](#ShutterSpeed)
    * [new ShutterSpeed(value_)](#new_ShutterSpeed_new)
    * _instance_
        * [.label](#ShutterSpeed+label) : <code>string</code>
        * [.value](#ShutterSpeed+value) : <code>number</code>
        * [.seconds](#ShutterSpeed+seconds) : <code>number</code>
        * [.stop](#ShutterSpeed+stop) : <code>number</code>
        * [.toJSON()](#ShutterSpeed+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.ID](#ShutterSpeed.ID) : <code>enum</code>
        * [.OneHalfValues](#ShutterSpeed.OneHalfValues) : <code>enum</code>
        * [.OneThirdValues](#ShutterSpeed.OneThirdValues) : <code>enum</code>
        * [.forLabel(label)](#ShutterSpeed.forLabel) ⇒ [<code>ShutterSpeed</code>](#ShutterSpeed) \| <code>null</code>

<a name="new_ShutterSpeed_new"></a>

## new ShutterSpeed(value_)
Encapsulate Object for a Shutter Speed value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value_</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="ShutterSpeed+label"></a>

## shutterSpeed.label : <code>string</code>
**Kind**: instance property of [<code>ShutterSpeed</code>](#ShutterSpeed)  
**Read only**: true  
<a name="ShutterSpeed+value"></a>

## shutterSpeed.value : <code>number</code>
**Kind**: instance property of [<code>ShutterSpeed</code>](#ShutterSpeed)  
**Read only**: true  
<a name="ShutterSpeed+seconds"></a>

## shutterSpeed.seconds : <code>number</code>
**Kind**: instance property of [<code>ShutterSpeed</code>](#ShutterSpeed)  
**Read only**: true  
<a name="ShutterSpeed+stop"></a>

## shutterSpeed.stop : <code>number</code>
**Kind**: instance property of [<code>ShutterSpeed</code>](#ShutterSpeed)  
**Read only**: true  
<a name="ShutterSpeed+toJSON"></a>

## shutterSpeed.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>ShutterSpeed</code>](#ShutterSpeed)  
<a name="ShutterSpeed.ID"></a>

## ShutterSpeed.ID : <code>enum</code>
**Kind**: static enum of [<code>ShutterSpeed</code>](#ShutterSpeed)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>Auto</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>Bulb</td><td><code>number</code></td><td><code>12</code></td>
    </tr><tr>
    <td>NotValid</td><td><code>number</code></td><td><code>4294967295</code></td>
    </tr>  </tbody>
</table>

<a name="ShutterSpeed.OneHalfValues"></a>

## ShutterSpeed.OneHalfValues : <code>enum</code>
**Kind**: static enum of [<code>ShutterSpeed</code>](#ShutterSpeed)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>16</td><td><code>number</code></td><td><code>30</code></td>
    </tr><tr>
    <td>19</td><td><code>number</code></td><td><code>25</code></td>
    </tr><tr>
    <td>20</td><td><code>number</code></td><td><code>20</code></td>
    </tr><tr>
    <td>24</td><td><code>number</code></td><td><code>15</code></td>
    </tr><tr>
    <td>27</td><td><code>number</code></td><td><code>13</code></td>
    </tr><tr>
    <td>28</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>32</td><td><code>number</code></td><td><code>8</code></td>
    </tr><tr>
    <td>36</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>37</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>40</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>43</td><td><code>number</code></td><td><code>3.2</code></td>
    </tr><tr>
    <td>44</td><td><code>number</code></td><td><code>3</code></td>
    </tr><tr>
    <td>45</td><td><code>number</code></td><td><code>2.5</code></td>
    </tr><tr>
    <td>48</td><td><code>number</code></td><td><code>2</code></td>
    </tr><tr>
    <td>51</td><td><code>number</code></td><td><code>1.6</code></td>
    </tr><tr>
    <td>52</td><td><code>number</code></td><td><code>1.5</code></td>
    </tr><tr>
    <td>53</td><td><code>number</code></td><td><code>1.3</code></td>
    </tr><tr>
    <td>56</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>59</td><td><code>number</code></td><td><code>0.8</code></td>
    </tr><tr>
    <td>60</td><td><code>number</code></td><td><code>0.7</code></td>
    </tr><tr>
    <td>61</td><td><code>number</code></td><td><code>0.6</code></td>
    </tr><tr>
    <td>64</td><td><code>number</code></td><td><code>0.5</code></td>
    </tr><tr>
    <td>67</td><td><code>number</code></td><td><code>0.4</code></td>
    </tr><tr>
    <td>68</td><td><code>number</code></td><td><code>0.3</code></td>
    </tr><tr>
    <td>72</td><td><code>number</code></td><td><code>0.25</code></td>
    </tr><tr>
    <td>75</td><td><code>number</code></td><td><code>0.2</code></td>
    </tr><tr>
    <td>76</td><td><code>number</code></td><td><code>0.16666666666666666</code></td>
    </tr><tr>
    <td>80</td><td><code>number</code></td><td><code>0.125</code></td>
    </tr><tr>
    <td>84</td><td><code>number</code></td><td><code>0.1</code></td>
    </tr><tr>
    <td>85</td><td><code>number</code></td><td><code>0.07692307692307693</code></td>
    </tr><tr>
    <td>88</td><td><code>number</code></td><td><code>0.06666666666666667</code></td>
    </tr><tr>
    <td>92</td><td><code>number</code></td><td><code>0.05</code></td>
    </tr><tr>
    <td>93</td><td><code>number</code></td><td><code>0.04</code></td>
    </tr><tr>
    <td>96</td><td><code>number</code></td><td><code>0.03333333333333333</code></td>
    </tr><tr>
    <td>99</td><td><code>number</code></td><td><code>0.025</code></td>
    </tr><tr>
    <td>100</td><td><code>number</code></td><td><code>0.022222222222222223</code></td>
    </tr><tr>
    <td>101</td><td><code>number</code></td><td><code>0.02</code></td>
    </tr><tr>
    <td>104</td><td><code>number</code></td><td><code>0.016666666666666666</code></td>
    </tr><tr>
    <td>107</td><td><code>number</code></td><td><code>0.0125</code></td>
    </tr><tr>
    <td>108</td><td><code>number</code></td><td><code>0.011111111111111112</code></td>
    </tr><tr>
    <td>109</td><td><code>number</code></td><td><code>0.01</code></td>
    </tr><tr>
    <td>112</td><td><code>number</code></td><td><code>0.008</code></td>
    </tr><tr>
    <td>115</td><td><code>number</code></td><td><code>0.00625</code></td>
    </tr><tr>
    <td>116</td><td><code>number</code></td><td><code>0.005555555555555556</code></td>
    </tr><tr>
    <td>117</td><td><code>number</code></td><td><code>0.005</code></td>
    </tr><tr>
    <td>120</td><td><code>number</code></td><td><code>0.004</code></td>
    </tr><tr>
    <td>123</td><td><code>number</code></td><td><code>0.003125</code></td>
    </tr><tr>
    <td>124</td><td><code>number</code></td><td><code>0.002857142857142857</code></td>
    </tr><tr>
    <td>125</td><td><code>number</code></td><td><code>0.0025</code></td>
    </tr><tr>
    <td>128</td><td><code>number</code></td><td><code>0.002</code></td>
    </tr><tr>
    <td>131</td><td><code>number</code></td><td><code>0.0015625</code></td>
    </tr><tr>
    <td>132</td><td><code>number</code></td><td><code>0.0013333333333333333</code></td>
    </tr><tr>
    <td>133</td><td><code>number</code></td><td><code>0.00125</code></td>
    </tr><tr>
    <td>136</td><td><code>number</code></td><td><code>0.001</code></td>
    </tr><tr>
    <td>139</td><td><code>number</code></td><td><code>0.0008</code></td>
    </tr><tr>
    <td>140</td><td><code>number</code></td><td><code>0.0006666666666666666</code></td>
    </tr><tr>
    <td>141</td><td><code>number</code></td><td><code>0.000625</code></td>
    </tr><tr>
    <td>144</td><td><code>number</code></td><td><code>0.0005</code></td>
    </tr><tr>
    <td>147</td><td><code>number</code></td><td><code>0.0004</code></td>
    </tr><tr>
    <td>148</td><td><code>number</code></td><td><code>0.0003333333333333333</code></td>
    </tr><tr>
    <td>149</td><td><code>number</code></td><td><code>0.0003125</code></td>
    </tr><tr>
    <td>152</td><td><code>number</code></td><td><code>0.00025</code></td>
    </tr><tr>
    <td>155</td><td><code>number</code></td><td><code>0.0002</code></td>
    </tr><tr>
    <td>156</td><td><code>number</code></td><td><code>0.00016666666666666666</code></td>
    </tr><tr>
    <td>157</td><td><code>number</code></td><td><code>0.00015625</code></td>
    </tr><tr>
    <td>160</td><td><code>number</code></td><td><code>0.000125</code></td>
    </tr>  </tbody>
</table>

<a name="ShutterSpeed.OneThirdValues"></a>

## ShutterSpeed.OneThirdValues : <code>enum</code>
**Kind**: static enum of [<code>ShutterSpeed</code>](#ShutterSpeed)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>21</td><td><code>number</code></td><td><code>20</code></td>
    </tr><tr>
    <td>29</td><td><code>number</code></td><td><code>10</code></td>
    </tr><tr>
    <td>35</td><td><code>number</code></td><td><code>6</code></td>
    </tr><tr>
    <td>69</td><td><code>number</code></td><td><code>0.3</code></td>
    </tr><tr>
    <td>77</td><td><code>number</code></td><td><code>0.16666666666666666</code></td>
    </tr><tr>
    <td>83</td><td><code>number</code></td><td><code>0.1</code></td>
    </tr><tr>
    <td>91</td><td><code>number</code></td><td><code>0.05</code></td>
    </tr>  </tbody>
</table>

<a name="ShutterSpeed.forLabel"></a>

## ShutterSpeed.forLabel(label) ⇒ [<code>ShutterSpeed</code>](#ShutterSpeed) \| <code>null</code>
Create instance for label.

**Kind**: static method of [<code>ShutterSpeed</code>](#ShutterSpeed)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>label</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="StateEvent"></a>

# StateEvent ⇐ [<code>ApiIdentifier</code>](#ApiIdentifier)
**Kind**: global class  
**Extends**: [<code>ApiIdentifier</code>](#ApiIdentifier)  

* [StateEvent](#StateEvent) ⇐ [<code>ApiIdentifier</code>](#ApiIdentifier)
    * [new StateEvent(identifier)](#new_StateEvent_new)
    * _instance_
        * [.label](#ApiIdentifier+label) : <code>string</code>
        * [.identifier](#ApiIdentifier+identifier) : <code>number</code>
        * [.equalTo(other)](#StateEvent+equalTo) ⇒ <code>boolean</code>
        * [.Symbol_toPrimitive(hint)](#ApiIdentifier+Symbol_toPrimitive) ⇒ <code>string</code> \| <code>number</code> \| <code>null</code>
        * [.toJSON()](#ApiIdentifier+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.ID](#StateEvent.ID) : <code>enum</code>

<a name="new_StateEvent_new"></a>

## new StateEvent(identifier)
Encapsulate Object Event Identifiers For Easy Read And Debug

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>identifier</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+label"></a>

## stateEvent.label : <code>string</code>
**Kind**: instance property of [<code>StateEvent</code>](#StateEvent)  
**Read only**: true  
<a name="ApiIdentifier+identifier"></a>

## stateEvent.identifier : <code>number</code>
**Kind**: instance property of [<code>StateEvent</code>](#StateEvent)  
**Read only**: true  
<a name="StateEvent+equalTo"></a>

## stateEvent.equalTo(other) ⇒ <code>boolean</code>
**Kind**: instance method of [<code>StateEvent</code>](#StateEvent)  
**Overrides**: [<code>equalTo</code>](#ApiIdentifier+equalTo)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Description</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>other</td><td><code>number</code> | <code><a href="#StateEvent">StateEvent</a></code></td><td><p>The other value</p>
</td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+Symbol_toPrimitive"></a>

## stateEvent.Symbol\_toPrimitive(hint) ⇒ <code>string</code> \| <code>number</code> \| <code>null</code>
Allows type cast to number and string.The string will be a hexadecimal code representation of the number

**Kind**: instance method of [<code>StateEvent</code>](#StateEvent)  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>hint</td><td><code>string</code></td>
    </tr>  </tbody>
</table>

<a name="ApiIdentifier+toJSON"></a>

## stateEvent.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>StateEvent</code>](#StateEvent)  
<a name="StateEvent.ID"></a>

## StateEvent.ID : <code>enum</code>
**Kind**: static enum of [<code>StateEvent</code>](#StateEvent)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>AfResult</td><td><code>number</code></td><td><code>777</code></td>
    </tr><tr>
    <td>All</td><td><code>number</code></td><td><code>768</code></td>
    </tr><tr>
    <td>BulbExposureTime</td><td><code>number</code></td><td><code>784</code></td>
    </tr><tr>
    <td>CaptureError</td><td><code>number</code></td><td><code>773</code></td>
    </tr><tr>
    <td>InternalError</td><td><code>number</code></td><td><code>774</code></td>
    </tr><tr>
    <td>JobStatusChanged</td><td><code>number</code></td><td><code>770</code></td>
    </tr><tr>
    <td>PowerZoomInfoChanged</td><td><code>number</code></td><td><code>785</code></td>
    </tr><tr>
    <td>ShutDownTimerUpdate</td><td><code>number</code></td><td><code>772</code></td>
    </tr><tr>
    <td>Shutdown</td><td><code>number</code></td><td><code>769</code></td>
    </tr><tr>
    <td>WillSoonShutDown</td><td><code>number</code></td><td><code>771</code></td>
    </tr>  </tbody>
</table>

<a name="TimeZone"></a>

# TimeZone
**Kind**: global class  
**Implements**: [<code>PropertyValue</code>](#PropertyValue)  

* [TimeZone](#TimeZone)
    * [new TimeZone(value_)](#new_TimeZone_new)
    * _instance_
        * [.label](#TimeZone+label) : <code>string</code>
        * [.value](#TimeZone+value) : <code>number</code>
        * [.zone](#TimeZone+zone) : <code>number</code>
        * [.difference](#TimeZone+difference) : <code>number</code>
        * [.toJSON()](#TimeZone+toJSON) ⇒ <code>Object</code>
    * _static_
        * [.Zones](#TimeZone.Zones) : <code>enum</code>

<a name="new_TimeZone_new"></a>

## new TimeZone(value_)
TimeZone property value

<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>value_</td><td><code>number</code></td>
    </tr>  </tbody>
</table>

<a name="TimeZone+label"></a>

## timeZone.label : <code>string</code>
**Kind**: instance property of [<code>TimeZone</code>](#TimeZone)  
**Read only**: true  
<a name="TimeZone+value"></a>

## timeZone.value : <code>number</code>
**Kind**: instance property of [<code>TimeZone</code>](#TimeZone)  
**Read only**: true  
<a name="TimeZone+zone"></a>

## timeZone.zone : <code>number</code>
**Kind**: instance property of [<code>TimeZone</code>](#TimeZone)  
**Read only**: true  
<a name="TimeZone+difference"></a>

## timeZone.difference : <code>number</code>
**Kind**: instance property of [<code>TimeZone</code>](#TimeZone)  
**Read only**: true  
<a name="TimeZone+toJSON"></a>

## timeZone.toJSON() ⇒ <code>Object</code>
**Kind**: instance method of [<code>TimeZone</code>](#TimeZone)  
<a name="TimeZone.Zones"></a>

## TimeZone.Zones : <code>enum</code>
**Kind**: static enum of [<code>TimeZone</code>](#TimeZone)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>0</td><td><code>string</code></td><td><code>&quot;None&quot;</code></td>
    </tr><tr>
    <td>1</td><td><code>string</code></td><td><code>&quot;Chatham Islands&quot;</code></td>
    </tr><tr>
    <td>2</td><td><code>string</code></td><td><code>&quot;Wellington&quot;</code></td>
    </tr><tr>
    <td>3</td><td><code>string</code></td><td><code>&quot;Solomon Island&quot;</code></td>
    </tr><tr>
    <td>4</td><td><code>string</code></td><td><code>&quot;Sydney&quot;</code></td>
    </tr><tr>
    <td>5</td><td><code>string</code></td><td><code>&quot;Adeladie&quot;</code></td>
    </tr><tr>
    <td>6</td><td><code>string</code></td><td><code>&quot;Tokyo&quot;</code></td>
    </tr><tr>
    <td>7</td><td><code>string</code></td><td><code>&quot;Hong Kong&quot;</code></td>
    </tr><tr>
    <td>8</td><td><code>string</code></td><td><code>&quot;Bangkok&quot;</code></td>
    </tr><tr>
    <td>9</td><td><code>string</code></td><td><code>&quot;Yangon&quot;</code></td>
    </tr><tr>
    <td>10</td><td><code>string</code></td><td><code>&quot;Dacca&quot;</code></td>
    </tr><tr>
    <td>11</td><td><code>string</code></td><td><code>&quot;Kathmandu&quot;</code></td>
    </tr><tr>
    <td>12</td><td><code>string</code></td><td><code>&quot;Delhi&quot;</code></td>
    </tr><tr>
    <td>13</td><td><code>string</code></td><td><code>&quot;Karachi&quot;</code></td>
    </tr><tr>
    <td>14</td><td><code>string</code></td><td><code>&quot;Kabul&quot;</code></td>
    </tr><tr>
    <td>15</td><td><code>string</code></td><td><code>&quot;Dubai&quot;</code></td>
    </tr><tr>
    <td>16</td><td><code>string</code></td><td><code>&quot;Tehran&quot;</code></td>
    </tr><tr>
    <td>17</td><td><code>string</code></td><td><code>&quot;Moscow&quot;</code></td>
    </tr><tr>
    <td>18</td><td><code>string</code></td><td><code>&quot;Cairo&quot;</code></td>
    </tr><tr>
    <td>19</td><td><code>string</code></td><td><code>&quot;Paris&quot;</code></td>
    </tr><tr>
    <td>20</td><td><code>string</code></td><td><code>&quot;London&quot;</code></td>
    </tr><tr>
    <td>21</td><td><code>string</code></td><td><code>&quot;Azores&quot;</code></td>
    </tr><tr>
    <td>22</td><td><code>string</code></td><td><code>&quot;Fernando de Noronha&quot;</code></td>
    </tr><tr>
    <td>23</td><td><code>string</code></td><td><code>&quot;São Paulo&quot;</code></td>
    </tr><tr>
    <td>24</td><td><code>string</code></td><td><code>&quot;Newfoundland&quot;</code></td>
    </tr><tr>
    <td>25</td><td><code>string</code></td><td><code>&quot;Santiago&quot;</code></td>
    </tr><tr>
    <td>26</td><td><code>string</code></td><td><code>&quot;Caracas&quot;</code></td>
    </tr><tr>
    <td>27</td><td><code>string</code></td><td><code>&quot;New York&quot;</code></td>
    </tr><tr>
    <td>28</td><td><code>string</code></td><td><code>&quot;Chicago&quot;</code></td>
    </tr><tr>
    <td>29</td><td><code>string</code></td><td><code>&quot;Denver&quot;</code></td>
    </tr><tr>
    <td>30</td><td><code>string</code></td><td><code>&quot;Los Angeles&quot;</code></td>
    </tr><tr>
    <td>31</td><td><code>string</code></td><td><code>&quot;Anchorage&quot;</code></td>
    </tr><tr>
    <td>32</td><td><code>string</code></td><td><code>&quot;Honolulu&quot;</code></td>
    </tr><tr>
    <td>33</td><td><code>string</code></td><td><code>&quot;Samoa&quot;</code></td>
    </tr><tr>
    <td>34</td><td><code>string</code></td><td><code>&quot;Riyadh&quot;</code></td>
    </tr><tr>
    <td>35</td><td><code>string</code></td><td><code>&quot;Manaus&quot;</code></td>
    </tr><tr>
    <td>256</td><td><code>string</code></td><td><code>&quot;UTC&quot;</code></td>
    </tr><tr>
    <td>65535</td><td><code>string</code></td><td><code>&quot;UTC&quot;</code></td>
    </tr>  </tbody>
</table>

<a name="Volume"></a>

# Volume
**Kind**: global class  

* [Volume](#Volume)
    * _instance_
        * [.label](#Volume+label) ⇒ <code>string</code>
        * [.storageType](#Volume+storageType) ⇒ <code>number</code>
        * [.isReadable](#Volume+isReadable) ⇒ <code>boolean</code>
        * [.isWritable](#Volume+isWritable) ⇒ <code>boolean</code>
        * [.freeCapacity](#Volume+freeCapacity) ⇒ <code>number</code>
        * [.maximumCapacity](#Volume+maximumCapacity) ⇒ <code>number</code>
        * [.length](#Volume+length) ⇒ <code>number</code>
        * [.getEntries()](#Volume+getEntries) ⇒ [<code>Array.&lt;DirectoryEntry&gt;</code>](#DirectoryEntry)
    * _static_
        * [.StorageType](#Volume.StorageType) : <code>enum</code>

<a name="Volume+label"></a>

## volume.label ⇒ <code>string</code>
**Kind**: instance property of [<code>Volume</code>](#Volume)  
**Read only**: true  
<a name="Volume+storageType"></a>

## volume.storageType ⇒ <code>number</code>
Storage type

**Kind**: instance property of [<code>Volume</code>](#Volume)  
**Read only**: true  
**See**: Volume.StorageType  
<a name="Volume+isReadable"></a>

## volume.isReadable ⇒ <code>boolean</code>
**Kind**: instance property of [<code>Volume</code>](#Volume)  
<a name="Volume+isWritable"></a>

## volume.isWritable ⇒ <code>boolean</code>
**Kind**: instance property of [<code>Volume</code>](#Volume)  
<a name="Volume+freeCapacity"></a>

## volume.freeCapacity ⇒ <code>number</code>
**Kind**: instance property of [<code>Volume</code>](#Volume)  
<a name="Volume+maximumCapacity"></a>

## volume.maximumCapacity ⇒ <code>number</code>
**Kind**: instance property of [<code>Volume</code>](#Volume)  
<a name="Volume+length"></a>

## volume.length ⇒ <code>number</code>
Entry count

**Kind**: instance property of [<code>Volume</code>](#Volume)  
<a name="Volume+getEntries"></a>

## volume.getEntries() ⇒ [<code>Array.&lt;DirectoryEntry&gt;</code>](#DirectoryEntry)
**Kind**: instance method of [<code>Volume</code>](#Volume)  
<a name="Volume.StorageType"></a>

## Volume.StorageType : <code>enum</code>
**Kind**: static enum of [<code>Volume</code>](#Volume)  
**Read only**: true  
**Properties**

<table>
  <thead>
    <tr>
      <th>Name</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>CFast</td><td><code>number</code></td><td><code>5</code></td>
    </tr><tr>
    <td>CompactFlash</td><td><code>number</code></td><td><code>1</code></td>
    </tr><tr>
    <td>HardDrive</td><td><code>number</code></td><td><code>4</code></td>
    </tr><tr>
    <td>NoMemoryCard</td><td><code>number</code></td><td><code>0</code></td>
    </tr><tr>
    <td>SDCard</td><td><code>number</code></td><td><code>2</code></td>
    </tr>  </tbody>
</table>

<a name="watchCameras"></a>

# watchCameras ⇒ <code>function</code>
Watch for camera events

**Kind**: global constant  
**Returns**: <code>function</code> - stop  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th><th>Default</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>[timeout]</td><td><code>int</code></td><td><code>1000</code></td>
    </tr>  </tbody>
</table>

<a name="cameraBrowser"></a>

# cameraBrowser : [<code>CameraBrowser</code>](#CameraBrowser)
Global CameraBrowser instance

**Kind**: global constant  
<a name="EventCallback"></a>

# EventCallback : <code>function</code>
**Kind**: global typedef  
<table>
  <thead>
    <tr>
      <th>Param</th><th>Type</th>
    </tr>
  </thead>
  <tbody>
<tr>
    <td>eventName</td><td><code>string</code></td>
    </tr><tr>
    <td>event</td><td><code><a href="#CameraDeviceEvent">CameraDeviceEvent</a></code> | <code><a href="#ApiError">ApiError</a></code></td>
    </tr>  </tbody>
</table>

<a name="CameraPropertyValue"></a>

# CameraPropertyValue : <code>string</code> \| <code>number</code> \| <code>Array.&lt;number&gt;</code> \| [<code>PropertyValue</code>](#PropertyValue)
**Kind**: global typedef  
