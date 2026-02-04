#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "circom.hpp"
#include "calcwit.hpp"
#include "fr.hpp"
void MultiMux1_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void MultiMux1_0_run(uint ctx_index,Circom_CalcWit* ctx);
void Mux1_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Mux1_1_run(uint ctx_index,Circom_CalcWit* ctx);
void Num2Bits_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void Num2Bits_2_run(uint ctx_index,Circom_CalcWit* ctx);
void LessThan_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void LessThan_3_run(uint ctx_index,Circom_CalcWit* ctx);
void GreaterThan_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void GreaterThan_4_run(uint ctx_index,Circom_CalcWit* ctx);
void NOT_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void NOT_5_run(uint ctx_index,Circom_CalcWit* ctx);
void OR_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void OR_6_run(uint ctx_index,Circom_CalcWit* ctx);
void AND_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void AND_7_run(uint ctx_index,Circom_CalcWit* ctx);
void IsZero_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsZero_8_run(uint ctx_index,Circom_CalcWit* ctx);
void IsEqual_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void IsEqual_9_run(uint ctx_index,Circom_CalcWit* ctx);
void XOR_10_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void XOR_10_run(uint ctx_index,Circom_CalcWit* ctx);
void main_template_11_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather);
void main_template_11_run(uint ctx_index,Circom_CalcWit* ctx);
Circom_TemplateFunction _functionTable[12] = { 
MultiMux1_0_run,
Mux1_1_run,
Num2Bits_2_run,
LessThan_3_run,
GreaterThan_4_run,
NOT_5_run,
OR_6_run,
AND_7_run,
IsZero_8_run,
IsEqual_9_run,
XOR_10_run,
main_template_11_run };
Circom_TemplateFunction _functionTableParallel[12] = { 
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL,
NULL };
uint get_main_input_signal_start() {return 3;}

uint get_main_input_signal_no() {return 2;}

uint get_total_signal_no() {return 999;}

uint get_number_of_components() {return 69;}

uint get_size_of_input_hashmap() {return 256;}

uint get_size_of_witness() {return 999;}

uint get_size_of_constants() {return 13;}

uint get_size_of_io_map() {return 0;}

uint get_size_of_bus_field_map() {return 0;}

void release_memory_component(Circom_CalcWit* ctx, uint pos) {{

if (pos != 0){{

if(ctx->componentMemory[pos].subcomponents)
delete []ctx->componentMemory[pos].subcomponents;

if(ctx->componentMemory[pos].subcomponentsParallel)
delete []ctx->componentMemory[pos].subcomponentsParallel;

if(ctx->componentMemory[pos].outputIsSet)
delete []ctx->componentMemory[pos].outputIsSet;

if(ctx->componentMemory[pos].mutexes)
delete []ctx->componentMemory[pos].mutexes;

if(ctx->componentMemory[pos].cvs)
delete []ctx->componentMemory[pos].cvs;

if(ctx->componentMemory[pos].sbct)
delete []ctx->componentMemory[pos].sbct;

}}


}}


// function declarations
// template declarations
void MultiMux1_0_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 0;
ctx->componentMemory[coffset].templateName = "MultiMux1";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void MultiMux1_0_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[2];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 1ull;
// load src
// end load src
lvar[1] = 0ull;
while(Fr_isTrue(Fr_lt(lvar[1],1ull))){
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_add(Fr_mul(Fr_sub(signalValues[mySignalStart + 2],signalValues[mySignalStart + 1]),signalValues[mySignalStart + 3]),signalValues[mySignalStart + 1]);
// load src
// end load src
lvar[1] = 1ull;
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void Mux1_1_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 1;
ctx->componentMemory[coffset].templateName = "Mux1";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 3;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void Mux1_1_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[2];
u64 lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "mux";
MultiMux1_0_create(mySignalStart+4,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
// load src
// end load src
lvar[0] = 0ull;
// load src
// end load src
lvar[0] = 0ull;
while(Fr_isTrue(Fr_lt(lvar[0],2ull))){
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + ((0 + (1 * Fr_toInt(lvar[0]))) + 1)] = signalValues[mySignalStart + ((1 * Fr_toInt(lvar[0])) + 1)];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
// load src
// end load src
lvar[0] = Fr_add(lvar[0],1ull);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = signalValues[mySignalStart + 3];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
MultiMux1_0_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void Num2Bits_2_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 2;
ctx->componentMemory[coffset].templateName = "Num2Bits";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void Num2Bits_2_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[4];
u64 lvar[4];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 253ull;
// load src
// end load src
lvar[1] = 0ull;
// load src
// end load src
lvar[2] = 1ull;
// load src
// end load src
lvar[3] = 0ull;
while(Fr_isTrue(Fr_lt(lvar[3],253ull))){
// load src
// end load src
signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)] = Fr_band(Fr_shr(signalValues[mySignalStart + 253],lvar[3]),1ull);
{
if (!Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],Fr_sub(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],1ull)),0ull))) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],Fr_sub(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],1ull)),0ull)));
}
// load src
// end load src
lvar[1] = Fr_add(lvar[1],Fr_mul(signalValues[mySignalStart + ((1 * Fr_toInt(lvar[3])) + 0)],lvar[2]));
// load src
// end load src
lvar[2] = Fr_add(lvar[2],lvar[2]);
// load src
// end load src
lvar[3] = Fr_add(lvar[3],1ull);
}
{
if (!Fr_isTrue(Fr_eq(lvar[1],signalValues[mySignalStart + 253]))) std::cout << "Failed assert in template/function " << myTemplateName << " line 38. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(lvar[1],signalValues[mySignalStart + 253])));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void LessThan_3_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 3;
ctx->componentMemory[coffset].templateName = "LessThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void LessThan_3_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 252ull;
{
std::string new_cmp_name = "n2b";
Num2Bits_2_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
if (!Fr_isTrue(1ull)) std::cout << "Failed assert in template/function " << myTemplateName << " line 90. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(1ull));
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 253] = Fr_sub(Fr_add(signalValues[mySignalStart + 1],0ull),signalValues[mySignalStart + 2]);
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Num2Bits_2_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = Fr_sub(1ull,ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 252]);
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void GreaterThan_4_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 4;
ctx->componentMemory[coffset].templateName = "GreaterThan";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void GreaterThan_4_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[1];
u64 lvar[1];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
lvar[0] = 252ull;
{
std::string new_cmp_name = "lt";
LessThan_3_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 1];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_3_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void NOT_5_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 5;
ctx->componentMemory[coffset].templateName = "NOT";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void NOT_5_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[4];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_sub(Fr_add(1ull,signalValues[mySignalStart + 1]),Fr_mul(2ull,signalValues[mySignalStart + 1]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void OR_6_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 6;
ctx->componentMemory[coffset].templateName = "OR";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void OR_6_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_sub(Fr_add(signalValues[mySignalStart + 1],signalValues[mySignalStart + 2]),Fr_mul(signalValues[mySignalStart + 1],signalValues[mySignalStart + 2]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void AND_7_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 7;
ctx->componentMemory[coffset].templateName = "AND";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void AND_7_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[1];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_mul(signalValues[mySignalStart + 1],signalValues[mySignalStart + 2]);
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void IsZero_8_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 8;
ctx->componentMemory[coffset].templateName = "IsZero";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 1;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void IsZero_8_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
if(Fr_isTrue(Fr_neq(signalValues[mySignalStart + 1],0ull))){
// load src
// end load src
signalValues[mySignalStart + 2] = Fr_div(1ull,signalValues[mySignalStart + 1]);
}else{
// load src
// end load src
signalValues[mySignalStart + 2] = 0ull;
}
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_add(Fr_mul(Fr_neg(signalValues[mySignalStart + 1]),signalValues[mySignalStart + 2]),1ull);
{
if (!Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 1],signalValues[mySignalStart + 0]),0ull))) std::cout << "Failed assert in template/function " << myTemplateName << " line 33. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 1],signalValues[mySignalStart + 0]),0ull)));
}
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void IsEqual_9_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 9;
ctx->componentMemory[coffset].templateName = "IsEqual";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[1]{0};
}

void IsEqual_9_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[1];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "isz";
IsZero_8_create(mySignalStart+3,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = Fr_sub(signalValues[mySignalStart + 2],signalValues[mySignalStart + 1]);
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsZero_8_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
signalValues[mySignalStart + 0] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
for (uint i = 0; i < 1; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void XOR_10_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 10;
ctx->componentMemory[coffset].templateName = "XOR";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[0];
}

void XOR_10_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[5];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
// load src
// end load src
signalValues[mySignalStart + 0] = Fr_sub(Fr_add(signalValues[mySignalStart + 1],signalValues[mySignalStart + 2]),Fr_mul(Fr_mul(2ull,signalValues[mySignalStart + 1]),signalValues[mySignalStart + 2]));
for (uint i = 0; i < 0; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void main_template_11_create(uint soffset,uint coffset,Circom_CalcWit* ctx,std::string componentName,uint componentFather){
ctx->componentMemory[coffset].templateId = 11;
ctx->componentMemory[coffset].templateName = "main_template";
ctx->componentMemory[coffset].signalStart = soffset;
ctx->componentMemory[coffset].inputCounter = 2;
ctx->componentMemory[coffset].componentName = componentName;
ctx->componentMemory[coffset].idFather = componentFather;
ctx->componentMemory[coffset].subcomponents = new uint[46]{0};
}

void main_template_11_run(uint ctx_index,Circom_CalcWit* ctx){
u64* signalValues = ctx->signalValues;
u64 expaux[3];
u64 lvar[0];
u64 mySignalStart = ctx->componentMemory[ctx_index].signalStart;
std::string myTemplateName = ctx->componentMemory[ctx_index].templateName;
std::string myComponentName = ctx->componentMemory[ctx_index].componentName;
u64 myFather = ctx->componentMemory[ctx_index].idFather;
u64 myId = ctx_index;
u32* mySubcomponents = ctx->componentMemory[ctx_index].subcomponents;
bool* mySubcomponentsParallel = ctx->componentMemory[ctx_index].subcomponentsParallel;
std::string* listOfTemplateMessages = ctx->listOfTemplateMessages;
uint sub_component_aux;
uint index_multiple_eq;
int cmp_index_ref_load = -1;
{
std::string new_cmp_name = "comp_0";
Mux1_1_create(mySignalStart+21,0+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[0] = 0+ctx_index+1;
}
{
std::string new_cmp_name = "comp_4";
GreaterThan_4_create(mySignalStart+375,34+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[1] = 34+ctx_index+1;
}
{
std::string new_cmp_name = "comp_5";
NOT_5_create(mySignalStart+667,45+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[2] = 45+ctx_index+1;
}
{
std::string new_cmp_name = "comp_6";
Mux1_1_create(mySignalStart+966,59+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[3] = 59+ctx_index+1;
}
{
std::string new_cmp_name = "comp_7";
OR_6_create(mySignalStart+990,65+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[4] = 65+ctx_index+1;
}
{
std::string new_cmp_name = "comp_8";
NOT_5_create(mySignalStart+993,66+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[5] = 66+ctx_index+1;
}
{
std::string new_cmp_name = "comp_9";
OR_6_create(mySignalStart+995,67+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[6] = 67+ctx_index+1;
}
{
std::string new_cmp_name = "comp_10";
OR_6_create(mySignalStart+29,2+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[7] = 2+ctx_index+1;
}
{
std::string new_cmp_name = "comp_11";
OR_6_create(mySignalStart+32,3+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[8] = 3+ctx_index+1;
}
{
std::string new_cmp_name = "comp_12";
NOT_5_create(mySignalStart+35,4+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[9] = 4+ctx_index+1;
}
{
std::string new_cmp_name = "comp_13";
OR_6_create(mySignalStart+37,5+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[10] = 5+ctx_index+1;
}
{
std::string new_cmp_name = "comp_14";
NOT_5_create(mySignalStart+40,6+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[11] = 6+ctx_index+1;
}
{
std::string new_cmp_name = "comp_15";
OR_6_create(mySignalStart+42,7+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[12] = 7+ctx_index+1;
}
{
std::string new_cmp_name = "comp_16";
OR_6_create(mySignalStart+45,8+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[13] = 8+ctx_index+1;
}
{
std::string new_cmp_name = "comp_17";
NOT_5_create(mySignalStart+48,9+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[14] = 9+ctx_index+1;
}
{
std::string new_cmp_name = "comp_18";
NOT_5_create(mySignalStart+50,10+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[15] = 10+ctx_index+1;
}
{
std::string new_cmp_name = "comp_19";
AND_7_create(mySignalStart+52,11+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[16] = 11+ctx_index+1;
}
{
std::string new_cmp_name = "comp_20";
OR_6_create(mySignalStart+55,12+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[17] = 12+ctx_index+1;
}
{
std::string new_cmp_name = "comp_21";
NOT_5_create(mySignalStart+58,13+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[18] = 13+ctx_index+1;
}
{
std::string new_cmp_name = "comp_22";
NOT_5_create(mySignalStart+60,14+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[19] = 14+ctx_index+1;
}
{
std::string new_cmp_name = "comp_23";
Mux1_1_create(mySignalStart+62,15+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[20] = 15+ctx_index+1;
}
{
std::string new_cmp_name = "comp_26";
IsEqual_9_create(mySignalStart+70,17+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[21] = 17+ctx_index+1;
}
{
std::string new_cmp_name = "comp_27";
NOT_5_create(mySignalStart+76,19+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[22] = 19+ctx_index+1;
}
{
std::string new_cmp_name = "comp_28";
XOR_10_create(mySignalStart+78,20+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[23] = 20+ctx_index+1;
}
{
std::string new_cmp_name = "comp_29";
OR_6_create(mySignalStart+81,21+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[24] = 21+ctx_index+1;
}
{
std::string new_cmp_name = "comp_30";
Mux1_1_create(mySignalStart+84,22+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[25] = 22+ctx_index+1;
}
{
std::string new_cmp_name = "comp_31";
Mux1_1_create(mySignalStart+92,24+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[26] = 24+ctx_index+1;
}
{
std::string new_cmp_name = "comp_34";
GreaterThan_4_create(mySignalStart+100,26+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[27] = 26+ctx_index+1;
}
{
std::string new_cmp_name = "comp_35";
NOT_5_create(mySignalStart+360,29+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[28] = 29+ctx_index+1;
}
{
std::string new_cmp_name = "comp_36";
NOT_5_create(mySignalStart+362,30+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[29] = 30+ctx_index+1;
}
{
std::string new_cmp_name = "comp_37";
OR_6_create(mySignalStart+364,31+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[30] = 31+ctx_index+1;
}
{
std::string new_cmp_name = "comp_39";
Mux1_1_create(mySignalStart+367,32+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[31] = 32+ctx_index+1;
}
{
std::string new_cmp_name = "comp_43";
Mux1_1_create(mySignalStart+635,37+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[32] = 37+ctx_index+1;
}
{
std::string new_cmp_name = "comp_46";
Mux1_1_create(mySignalStart+643,39+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[33] = 39+ctx_index+1;
}
{
std::string new_cmp_name = "comp_48";
Mux1_1_create(mySignalStart+651,41+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[34] = 41+ctx_index+1;
}
{
std::string new_cmp_name = "comp_49";
Mux1_1_create(mySignalStart+659,43+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[35] = 43+ctx_index+1;
}
{
std::string new_cmp_name = "comp_50";
AND_7_create(mySignalStart+669,46+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[36] = 46+ctx_index+1;
}
{
std::string new_cmp_name = "comp_51";
OR_6_create(mySignalStart+672,47+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[37] = 47+ctx_index+1;
}
{
std::string new_cmp_name = "comp_52";
Mux1_1_create(mySignalStart+675,48+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[38] = 48+ctx_index+1;
}
{
std::string new_cmp_name = "comp_53";
Mux1_1_create(mySignalStart+683,50+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[39] = 50+ctx_index+1;
}
{
std::string new_cmp_name = "comp_54";
Mux1_1_create(mySignalStart+691,52+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[40] = 52+ctx_index+1;
}
{
std::string new_cmp_name = "comp_57";
LessThan_3_create(mySignalStart+699,54+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[41] = 54+ctx_index+1;
}
{
std::string new_cmp_name = "comp_58";
NOT_5_create(mySignalStart+956,56+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[42] = 56+ctx_index+1;
}
{
std::string new_cmp_name = "comp_59";
Mux1_1_create(mySignalStart+958,57+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[43] = 57+ctx_index+1;
}
{
std::string new_cmp_name = "comp_61";
Mux1_1_create(mySignalStart+974,61+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[44] = 61+ctx_index+1;
}
{
std::string new_cmp_name = "comp_62";
Mux1_1_create(mySignalStart+982,63+ctx_index+1,ctx,new_cmp_name,myId);
mySubcomponents[45] = 63+ctx_index+1;
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 0;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 4] = 6822900150086823476ull;
{
if (!Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 4],1ull),6822900150086823476ull))) std::cout << "Failed assert in template/function " << myTemplateName << " line 20. " <<  "Followed trace of components: " << ctx->getTrace(myId) << std::endl;
assert(Fr_isTrue(Fr_eq(Fr_mul(signalValues[mySignalStart + 4],1ull),6822900150086823476ull)));
}
// load src
// end load src
signalValues[mySignalStart + 5] = 0ull;
// load src
// end load src
signalValues[mySignalStart + 6] = Fr_sub(signalValues[mySignalStart + 4],signalValues[mySignalStart + 5]);
{
uint cmp_index_ref = 1;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 1;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 6];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
GreaterThan_4_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 2;
// load src
cmp_index_ref_load = 1;
cmp_index_ref_load = 1;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[1]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 3;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 3;
// load src
cmp_index_ref_load = 2;
cmp_index_ref_load = 2;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[2]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 3;
// load src
cmp_index_ref_load = 0;
cmp_index_ref_load = 0;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[0]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 4;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 4;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 5;
// load src
cmp_index_ref_load = 4;
cmp_index_ref_load = 4;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[4]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 6;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 6;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 7;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 7;
// load src
cmp_index_ref_load = 6;
cmp_index_ref_load = 6;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[6]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 8;
// load src
cmp_index_ref_load = 5;
cmp_index_ref_load = 5;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[5]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 8;
// load src
cmp_index_ref_load = 7;
cmp_index_ref_load = 7;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[7]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 9;
// load src
cmp_index_ref_load = 8;
cmp_index_ref_load = 8;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[8]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 10;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 10;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 11;
// load src
cmp_index_ref_load = 10;
cmp_index_ref_load = 10;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[10]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 12;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 12;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 13;
// load src
cmp_index_ref_load = 12;
cmp_index_ref_load = 12;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[12]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 13;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 14;
// load src
cmp_index_ref_load = 13;
cmp_index_ref_load = 13;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[13]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 15;
// load src
cmp_index_ref_load = 14;
cmp_index_ref_load = 14;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[14]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 16;
// load src
cmp_index_ref_load = 11;
cmp_index_ref_load = 11;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[11]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 16;
// load src
cmp_index_ref_load = 15;
cmp_index_ref_load = 15;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[15]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 17;
// load src
cmp_index_ref_load = 9;
cmp_index_ref_load = 9;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[9]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 17;
// load src
cmp_index_ref_load = 16;
cmp_index_ref_load = 16;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[16]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 18;
// load src
cmp_index_ref_load = 17;
cmp_index_ref_load = 17;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[17]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 19;
// load src
cmp_index_ref_load = 18;
cmp_index_ref_load = 18;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[18]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 20;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 20;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 20;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 7] = 14548162474639577817ull;
// load src
// end load src
signalValues[mySignalStart + 8] = 12983281506709331475ull;
{
uint cmp_index_ref = 21;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 7];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 21;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 8];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
IsEqual_9_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 22;
// load src
cmp_index_ref_load = 21;
cmp_index_ref_load = 21;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[21]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 23;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 23;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
XOR_10_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 24;
// load src
cmp_index_ref_load = 22;
cmp_index_ref_load = 22;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[22]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 24;
// load src
cmp_index_ref_load = 23;
cmp_index_ref_load = 23;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[23]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 25;
// load src
cmp_index_ref_load = 24;
cmp_index_ref_load = 24;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[24]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 25;
// load src
cmp_index_ref_load = 20;
cmp_index_ref_load = 20;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[20]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 25;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 26;
// load src
cmp_index_ref_load = 25;
cmp_index_ref_load = 25;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[25]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 26;
// load src
cmp_index_ref_load = 19;
cmp_index_ref_load = 19;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[19]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 26;
// load src
cmp_index_ref_load = 3;
cmp_index_ref_load = 3;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[3]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 9] = Fr_band(signalValues[mySignalStart + 2],signalValues[mySignalStart + 3]);
// load src
// end load src
signalValues[mySignalStart + 10] = Fr_bnot(signalValues[mySignalStart + 2]);
{
uint cmp_index_ref = 27;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 9];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 27;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 10];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
GreaterThan_4_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 28;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 29;
// load src
cmp_index_ref_load = 28;
cmp_index_ref_load = 28;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[28]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 30;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 30;
// load src
cmp_index_ref_load = 29;
cmp_index_ref_load = 29;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[29]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 11] = Fr_bnot(signalValues[mySignalStart + 2]);
{
uint cmp_index_ref = 31;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 15969839135450377938ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 31;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 11];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 31;
// load src
cmp_index_ref_load = 30;
cmp_index_ref_load = 30;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[30]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 12] = 10557910790515554005ull;
// load src
// end load src
signalValues[mySignalStart + 13] = 0ull;
// load src
// end load src
signalValues[mySignalStart + 14] = Fr_bxor(signalValues[mySignalStart + 12],signalValues[mySignalStart + 13]);
{
uint cmp_index_ref = 32;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 32;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 14];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 32;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 15] = 17985231351214559861ull;
// load src
// end load src
signalValues[mySignalStart + 16] = Fr_bxor(7718425886846723232ull,signalValues[mySignalStart + 15]);
{
uint cmp_index_ref = 33;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 33;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 16];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 33;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 32;
cmp_index_ref_load = 32;
cmp_index_ref_load = 33;
cmp_index_ref_load = 33;
// end load src
signalValues[mySignalStart + 17] = Fr_band(ctx->signalValues[ctx->componentMemory[mySubcomponents[32]].signalStart + 0],ctx->signalValues[ctx->componentMemory[mySubcomponents[33]].signalStart + 0]);
{
uint cmp_index_ref = 34;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 17];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 34;
// load src
cmp_index_ref_load = 31;
cmp_index_ref_load = 31;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[31]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 34;
// load src
cmp_index_ref_load = 27;
cmp_index_ref_load = 27;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[27]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 35;
// load src
cmp_index_ref_load = 34;
cmp_index_ref_load = 34;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[34]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 35;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 15634063055389091909ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 35;
// load src
cmp_index_ref_load = 26;
cmp_index_ref_load = 26;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[26]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 35;
cmp_index_ref_load = 35;
// end load src
signalValues[mySignalStart + 0] = ctx->signalValues[ctx->componentMemory[mySubcomponents[35]].signalStart + 0];
{
uint cmp_index_ref = 36;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 36;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
AND_7_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 37;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 37;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
OR_6_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 38;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 3];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 38;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 38;
// load src
cmp_index_ref_load = 37;
cmp_index_ref_load = 37;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[37]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 39;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 39;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = 1ull;
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 39;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 40;
// load src
cmp_index_ref_load = 39;
cmp_index_ref_load = 39;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[39]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 40;
// load src
cmp_index_ref_load = 38;
cmp_index_ref_load = 38;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[38]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 40;
// load src
cmp_index_ref_load = 36;
cmp_index_ref_load = 36;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[36]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 18] = Fr_bnot(signalValues[mySignalStart + 2]);
// load src
cmp_index_ref_load = 40;
cmp_index_ref_load = 40;
// end load src
signalValues[mySignalStart + 19] = ctx->signalValues[ctx->componentMemory[mySubcomponents[40]].signalStart + 0];
{
uint cmp_index_ref = 41;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 19];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 41;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = signalValues[mySignalStart + 18];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
LessThan_3_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 42;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
NOT_5_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 43;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 2];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 43;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = Fr_sub(signalValues[mySignalStart + 3],0ull);
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 43;
// load src
cmp_index_ref_load = 42;
cmp_index_ref_load = 42;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[42]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
// end load src
signalValues[mySignalStart + 20] = 0ull;
{
uint cmp_index_ref = 44;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = signalValues[mySignalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 44;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = Fr_sub(signalValues[mySignalStart + 20],signalValues[mySignalStart + 0]);
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 44;
// load src
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = 0ull;
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
{
uint cmp_index_ref = 45;
// load src
cmp_index_ref_load = 44;
cmp_index_ref_load = 44;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[44]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 45;
// load src
cmp_index_ref_load = 43;
cmp_index_ref_load = 43;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 2] = ctx->signalValues[ctx->componentMemory[mySubcomponents[43]].signalStart + 0];
// no need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter > 0);
}
{
uint cmp_index_ref = 45;
// load src
cmp_index_ref_load = 41;
cmp_index_ref_load = 41;
// end load src
ctx->signalValues[ctx->componentMemory[mySubcomponents[cmp_index_ref]].signalStart + 3] = ctx->signalValues[ctx->componentMemory[mySubcomponents[41]].signalStart + 0];
// need to run sub component
ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter -= 1;
assert(!(ctx->componentMemory[mySubcomponents[cmp_index_ref]].inputCounter));
Mux1_1_run(mySubcomponents[cmp_index_ref],ctx);
}
// load src
cmp_index_ref_load = 45;
cmp_index_ref_load = 45;
// end load src
signalValues[mySignalStart + 1] = ctx->signalValues[ctx->componentMemory[mySubcomponents[45]].signalStart + 0];
{
printf("<@> out0 = ");
}
{
printf(" ");
}
{
char* temp = Fr_element2str(signalValues[mySignalStart + 0]);
printf("%s",temp);
delete [] temp;
}
{
printf("\n");
}
{
printf("<@> out1 = ");
}
{
printf(" ");
}
{
char* temp = Fr_element2str(signalValues[mySignalStart + 1]);
printf("%s",temp);
delete [] temp;
}
{
printf("\n");
}
for (uint i = 0; i < 46; i++){
uint index_subc = ctx->componentMemory[ctx_index].subcomponents[i];
if (index_subc != 0){
assert(!(ctx->componentMemory[index_subc].inputCounter));
release_memory_component(ctx,index_subc);
}
}
}

void run(Circom_CalcWit* ctx){
main_template_11_create(1,0,ctx,"main",0);
main_template_11_run(0,ctx);
}

